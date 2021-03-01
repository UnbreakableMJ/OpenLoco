#include "PaintEntity.h"
#include "../Config.h"
#include "../Interop/Interop.hpp"
#include "../Map/Tile.h"
#include "../Things/Misc.h"
#include "../Things/ThingManager.h"
#include "../Vehicles/Vehicle.h"
#include "Paint.h"
#include "PaintMiscEntity.h"
#include "PaintVehicle.h"

using namespace OpenLoco::Interop;
using namespace OpenLoco::Ui::ViewportInteraction;

namespace OpenLoco::Paint
{
    template<typename FilterType>
    static void paintEntitiesWithFilter(PaintSession& session, const Map::map_pos& loc, FilterType&& filter)
    {
        auto* dpi = session.getContext();
        if (Config::get().vehicles_min_scale < dpi->zoom_level)
        {
            return;
        }

        if (loc.x >= 0x4000 || loc.y >= 0x4000)
        {
            return;
        }

        ThingManager::ThingTileList entities(loc);
        for (auto* entity : entities)
        {
            // TODO: Create a rect from dpi dims
            auto left = dpi->x;
            auto top = dpi->y;
            auto right = left + dpi->width;
            auto bottom = top + dpi->height;

            // TODO: Create a rect from sprite dims and use a contains function
            if (entity->sprite_top > bottom)
            {
                continue;
            }
            if (entity->sprite_bottom <= top)
            {
                continue;
            }
            if (entity->sprite_left > right)
            {
                continue;
            }
            if (entity->sprite_right <= left)
            {
                continue;
            }
            if (!filter(entity))
            {
                continue;
            }
            session.setCurrentItem(entity);
            session.setEntityPosition({ entity->x, entity->y });
            session.setItemType(InteractionItem::entity);
            switch (entity->base_type)
            {
                case thing_base_type::vehicle:
                    paintVehicleEntity(session, entity->asVehicle());
                    break;
                case thing_base_type::misc:
                    paintMiscEntity(session, entity->asMisc());
                    break;
            }
        }
    }

    // 0x0046FA88
    void paintEntities(PaintSession& session, const Map::map_pos& loc)
    {
        paintEntitiesWithFilter(session, loc, [](const thing_base*) { return true; });
    }

    static bool isEntityFlyingOrFloating(const thing_base* entity)
    {
        auto* vehicle = entity->asVehicle();
        if (vehicle == nullptr)
        {
            return false;
        }
        switch (vehicle->getTransportMode())
        {
            case TransportMode::air:
            case TransportMode::water:
                return true;
            case TransportMode::rail:
            case TransportMode::road:
                return false;
        }
        return false;
    }

    // 0x0046FB67
    void paintEntities2(PaintSession& session, const Map::map_pos& loc)
    {
        paintEntitiesWithFilter(session, loc, isEntityFlyingOrFloating);
    }
}
