#pragma once

#include <Arduino.h>
#include <inttypes.h>

struct ScopedPin
{
    explicit ScopedPin(uint8_t pin_number, uint8_t alive_value = HIGH);

    ~ScopedPin();

protected:
    uint8_t pin_number;
    uint8_t scope_left_value;
};

struct ScopedTogglePin
{
    explicit ScopedTogglePin(uint8_t pin_number);

    ~ScopedTogglePin();

protected:
    uint8_t pin_number;

    void toggle();
};

struct TogglePin
{
    explicit TogglePin(uint8_t pin_number);
    void toggle();

    protected : uint8_t pin_number;
};