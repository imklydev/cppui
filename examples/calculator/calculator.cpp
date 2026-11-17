/*
This is a simple calculator app example, made with AI asistance, to show how bigger apps can be built with cppui.
*/

#include "app.h"

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <string>

// Fonts and colors
Font smallFont = GetFont("JetBrainsMono.ttf", 16.0f);
Font largeFont = GetFont("JetBrainsMono.ttf", 32.0f);

Color DISPLAY_COLOR = {38, 38, 42, 255};
Color DIGIT_COLOR = {64, 64, 70, 255};
Color FUNCTION_COLOR = {115, 115, 125, 255};
Color OPERATOR_COLOR = {255, 149, 0, 255};
Color EQUALS_COLOR = {52, 199, 89, 255};
Color DIM_COLOR = {170, 170, 175, 255};

// Calculator logic lives in its own namespace to avoid name clashes with the framework
namespace calculator
{
    TextComponent *resultText = nullptr;
    TextComponent *expressionText = nullptr;

    std::string entry = "0";    // the number currently being typed
    double storedValue = 0;     // left-hand operand
    char pendingOperator = 0;   // +, -, *, /, %, ^ (0 if none)
    bool startNewNumber = true; // true if the next digit starts a new number
    bool hasError = false;

    const size_t MAX_DIGITS = 15;

    std::string FormatNumber(double value)
    {
        if (std::isnan(value) || std::isinf(value))
            return "Error";
        char buffer[64];
        std::snprintf(buffer, sizeof(buffer), "%.12g", value);
        return buffer;
    }

    double EntryValue()
    {
        return std::strtod(entry.c_str(), nullptr);
    }

    void UpdateDisplay()
    {
        resultText->ChangeText(entry);

        std::string expression = " ";
        if (pendingOperator)
            expression = FormatNumber(storedValue) + " " + pendingOperator;
        expressionText->ChangeText(expression);
    }

    void ShowError()
    {
        entry = "Error";
        hasError = true;
        pendingOperator = 0;
        startNewNumber = true;
        UpdateDisplay();
    }

    void Clear()
    {
        entry = "0";
        storedValue = 0;
        pendingOperator = 0;
        startNewNumber = true;
        hasError = false;
        UpdateDisplay();
    }

    // Typing

    void AddDigit(int digit)
    {
        if (hasError)
            Clear();
        if (startNewNumber)
        {
            entry = "0";
            startNewNumber = false;
        }
        if (entry.size() >= MAX_DIGITS)
            return;

        if (entry == "0")
            entry = std::to_string(digit);
        else if (entry == "-0")
            entry = "-" + std::to_string(digit);
        else
            entry += std::to_string(digit);
        UpdateDisplay();
    }

    void AddDecimalPoint()
    {
        if (hasError)
            Clear();
        if (startNewNumber)
        {
            entry = "0";
            startNewNumber = false;
        }
        if (entry.find('.') == std::string::npos)
            entry += '.';
        UpdateDisplay();
    }

    void Backspace()
    {
        if (hasError)
        {
            Clear();
            return;
        }
        if (startNewNumber)
            return;

        entry.pop_back();
        if (entry.empty() || entry == "-")
            entry = "0";
        UpdateDisplay();
    }

    void ToggleSign()
    {
        if (hasError || entry == "0")
            return;

        if (entry[0] == '-')
            entry.erase(0, 1);
        else
            entry.insert(0, "-");
        UpdateDisplay();
    }

    // Math

    // Returns false if the operation is invalid (e.g. divide by zero)
    bool Calculate(char op, double a, double b, double &result)
    {
        switch (op)
        {
        case '+':
            result = a + b;
            return true;
        case '-':
            result = a - b;
            return true;
        case '*':
            result = a * b;
            return true;
        case '/':
            if (b == 0)
                return false;
            result = a / b;
            return true;
        case '%':
            if (b == 0)
                return false;
            result = std::fmod(a, b);
            return true;
        case '^':
            result = std::pow(a, b);
            return !std::isnan(result) && !std::isinf(result);
        }
        return false;
    }

    void PressOperator(char op)
    {
        if (hasError)
            return;

        // "2 + 3 +" calculates 2 + 3 before moving on
        if (pendingOperator && !startNewNumber)
        {
            double result;
            if (!Calculate(pendingOperator, storedValue, EntryValue(), result))
            {
                ShowError();
                return;
            }
            storedValue = result;
            entry = FormatNumber(result);
        }
        else
        {
            storedValue = EntryValue();
        }

        pendingOperator = op;
        startNewNumber = true;
        UpdateDisplay();
    }

    void PressEquals()
    {
        if (hasError || !pendingOperator)
            return;

        double result;
        if (!Calculate(pendingOperator, storedValue, EntryValue(), result))
        {
            ShowError();
            return;
        }

        entry = FormatNumber(result);
        pendingOperator = 0;
        startNewNumber = true;
        UpdateDisplay();
    }

    // Applies a one-argument function (sqrt, square, ...) to the current number
    void ApplyFunction(double (*function)(double))
    {
        if (hasError)
            return;

        double result = function(EntryValue());
        if (std::isnan(result) || std::isinf(result))
        {
            ShowError();
            return;
        }

        entry = FormatNumber(result);
        startNewNumber = true;
        UpdateDisplay();
    }
}

// A colored button with a centered label
auto Key(const char *label, void (*onClick)(), Color color)
{
    const int KEY_SIZE = 72;
    const int KEY_GAP = 5;

    // clang-format off
    return MarginContainer(KEY_GAP, {
        Button(onClick, color, {
            CenteredContainer({Text(label, smallFont, WHITE)})->resize({KEY_SIZE, KEY_SIZE}),
        }),
    });
    // clang-format on
}

App Application()
{
    using namespace calculator;

    expressionText = Text(" ", smallFont, DIM_COLOR);
    resultText = Text("0", largeFont, WHITE);

    // clang-format off
    return App({
        Panel(DISPLAY_COLOR, {
            CenteredHorizontalContainer({
                CenteredVerticalContainer({
                    expressionText,
                    resultText,
                })->resize({WINDOW_WIDTH, NO_CHANGE}),
            })->resize({NO_CHANGE, 120}),
        }),

        CenteredContainer({
            HorizontalContainer({
                Key("sqrt", [] { ApplyFunction([](double x) { return std::sqrt(x); }); }, FUNCTION_COLOR),
                Key("x^2",  [] { ApplyFunction([](double x) { return x * x; }); },        FUNCTION_COLOR),
                Key("1/x",  [] { ApplyFunction([](double x) { return 1.0 / x; }); },      FUNCTION_COLOR),
                Key("^",    [] { PressOperator('^'); },                                   OPERATOR_COLOR),
            }),
            HorizontalContainer({
                Key("C",   Clear,                       FUNCTION_COLOR),
                Key("+/-", ToggleSign,                  FUNCTION_COLOR),
                Key("%",   [] { PressOperator('%'); },  FUNCTION_COLOR),
                Key("/",   [] { PressOperator('/'); },  OPERATOR_COLOR),
            }),
            HorizontalContainer({
                Key("7", [] { AddDigit(7); },           DIGIT_COLOR),
                Key("8", [] { AddDigit(8); },           DIGIT_COLOR),
                Key("9", [] { AddDigit(9); },           DIGIT_COLOR),
                Key("x", [] { PressOperator('*'); },    OPERATOR_COLOR),
            }),
            HorizontalContainer({
                Key("4", [] { AddDigit(4); },           DIGIT_COLOR),
                Key("5", [] { AddDigit(5); },           DIGIT_COLOR),
                Key("6", [] { AddDigit(6); },           DIGIT_COLOR),
                Key("-", [] { PressOperator('-'); },    OPERATOR_COLOR),
            }),
            HorizontalContainer({
                Key("1", [] { AddDigit(1); },           DIGIT_COLOR),
                Key("2", [] { AddDigit(2); },           DIGIT_COLOR),
                Key("3", [] { AddDigit(3); },           DIGIT_COLOR),
                Key("+", [] { PressOperator('+'); },    OPERATOR_COLOR),
            }),
            HorizontalContainer({
                Key("0",  [] { AddDigit(0); },          DIGIT_COLOR),
                Key(".",  AddDecimalPoint,              DIGIT_COLOR),
                Key("<-", Backspace,                    FUNCTION_COLOR),
                Key("=",  PressEquals,                  EQUALS_COLOR),
            }),
        })->resize({WINDOW_WIDTH, 6 * (72 + 2 * 5) + 20}),
    });
    // clang-format on
}