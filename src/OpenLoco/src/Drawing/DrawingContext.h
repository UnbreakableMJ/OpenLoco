#pragma once

#include "Graphics/Gfx.h"
#include "Graphics/PaletteMap.h"
#include "Types.hpp"
#include "Ui/Rect.h"
#include <cstdint>

namespace OpenLoco::Drawing
{
    class DrawingContext
    {
    public:
        virtual ~DrawingContext() = default;

        virtual void clear(Gfx::RenderTarget& rt, uint32_t fill) = 0;
        virtual void clearSingle(Gfx::RenderTarget& rt, uint8_t paletteId) = 0;

        virtual int16_t clipString(int16_t width, char* string) = 0;
        virtual uint16_t getStringWidth(const char* buffer) = 0;
        virtual uint16_t getMaxStringWidth(const char* buffer) = 0;

        virtual Ui::Point drawString(Gfx::RenderTarget& rt, int16_t x, int16_t y, AdvancedColour colour, void* str) = 0;

        virtual int16_t drawStringLeftWrapped(
            Gfx::RenderTarget& rt,
            int16_t x,
            int16_t y,
            int16_t width,
            AdvancedColour colour,
            string_id stringId,
            const void* args = nullptr)
            = 0;

        virtual void drawStringLeft(
            Gfx::RenderTarget& rt,
            int16_t x,
            int16_t y,
            AdvancedColour colour,
            string_id stringId,
            const void* args = nullptr)
            = 0;

        virtual void drawStringLeft(
            Gfx::RenderTarget& rt,
            Ui::Point* origin,
            AdvancedColour colour,
            string_id stringId,
            const void* args = nullptr)
            = 0;

        virtual void drawStringLeftClipped(
            Gfx::RenderTarget& rt,
            int16_t x,
            int16_t y,
            int16_t width,
            AdvancedColour colour,
            string_id stringId,
            const void* args = nullptr)
            = 0;

        virtual void drawStringRight(
            Gfx::RenderTarget& rt,
            int16_t x,
            int16_t y,
            AdvancedColour colour,
            string_id stringId,
            const void* args = nullptr)
            = 0;

        virtual void drawStringRightUnderline(
            Gfx::RenderTarget& rt,
            int16_t x,
            int16_t y,
            AdvancedColour colour,
            string_id stringId,
            const void* args)
            = 0;

        virtual void drawStringLeftUnderline(
            Gfx::RenderTarget& rt,
            int16_t x,
            int16_t y,
            AdvancedColour colour,
            string_id stringId,
            const void* args = nullptr)
            = 0;

        virtual void drawStringCentred(
            Gfx::RenderTarget& rt,
            int16_t x,
            int16_t y,
            AdvancedColour colour,
            string_id stringId,
            const void* args = nullptr)
            = 0;

        virtual void drawStringCentredClipped(
            Gfx::RenderTarget& rt,
            int16_t x,
            int16_t y,
            int16_t width,
            AdvancedColour colour,
            string_id stringId,
            const void* args = nullptr)
            = 0;

        virtual uint16_t drawStringCentredWrapped(
            Gfx::RenderTarget& rt,
            Ui::Point& origin,
            uint16_t width,
            AdvancedColour colour,
            string_id stringId,
            const void* args = nullptr)
            = 0;

        virtual void drawStringCentredRaw(
            Gfx::RenderTarget& rt,
            int16_t x,
            int16_t y,
            int16_t width,
            AdvancedColour colour,
            const void* args)
            = 0;

        virtual void drawStringYOffsets(Gfx::RenderTarget& rt, const Ui::Point& loc, AdvancedColour colour, const void* args, const int8_t* yOffsets) = 0;

        virtual uint16_t getStringWidthNewLined(const char* buffer) = 0;

        virtual std::pair<uint16_t, uint16_t> wrapString(char* buffer, uint16_t stringWidth) = 0;

        virtual void fillRect(Gfx::RenderTarget& rt, int16_t left, int16_t top, int16_t right, int16_t bottom, uint32_t colour) = 0;

        virtual void drawRect(Gfx::RenderTarget& rt, int16_t x, int16_t y, uint16_t dx, uint16_t dy, uint32_t colour) = 0;

        virtual void fillRectInset(Gfx::RenderTarget& rt, int16_t left, int16_t top, int16_t right, int16_t bottom, uint32_t colour, uint8_t flags) = 0;

        virtual void drawRectInset(Gfx::RenderTarget& rt, int16_t x, int16_t y, uint16_t dx, uint16_t dy, uint32_t colour, uint8_t flags) = 0;

        virtual void drawLine(Gfx::RenderTarget& rt, const Ui::Point& a, const Ui::Point& b, PaletteIndex_t colour) = 0;

        virtual void drawImage(Gfx::RenderTarget* rt, int16_t x, int16_t y, uint32_t image) = 0;

        virtual void drawImage(Gfx::RenderTarget& rt, const Ui::Point& pos, const ImageId& image) = 0;

        virtual void drawImageSolid(Gfx::RenderTarget& rt, const Ui::Point& pos, const ImageId& image, PaletteIndex_t paletteIndex) = 0;

        virtual void drawImagePaletteSet(Gfx::RenderTarget& rt, const Ui::Point& pos, const ImageId& image, Gfx::PaletteMap::View palette, const Gfx::G1Element* noiseImage) = 0;

        virtual int16_t getCurrentFontSpriteBase() = 0;

        virtual void setCurrentFontSpriteBase(int16_t base) = 0;
    };
}