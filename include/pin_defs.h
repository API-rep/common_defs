/******************************************************************************
 * @file Pin°defs.h
 * @brief Unified hardware state and mode abstractions for microcontrollers.
 * 
 * Provides standardized enums for GPIO states, physical configurations, 
 * and logic levels to ensure portability between projects and lib.
 * 
 * ****************************************************************************/

#pragma once

#include <cstdint>

// =============================================================================
// 1. PREPROCESSOR SAFETY GUARDS
// =============================================================================

	// --- 1. Exhaustive macro conflict detection ---
	// Prevents silent corruption of enum tokens by third-party #define macros
#if defined(Low) || defined(High) || \
    defined(Disable) || defined(Input) || defined(InputPullup) || defined(InputPulldown) || \
    defined(Output) || defined(OutputOpenDrain) || defined(InputOutput) || defined(Analog) || \
    defined(ActiveLow) || defined(ActiveHigh) || \
    defined(Inactive) || defined(Active)
	#error "Naming conflict: A macro (#define) is interfering with Pin enum values."
#endif

// =============================================================================
// 2. HARDWARE STATE AND CONFIGURATION
// =============================================================================

/**
 * @brief Physical electrical level of a pin
 */

enum class ActiveLevel : uint8_t {
	Unset = 0,
	ActiveLow  = 1,
	ActiveHigh = 2
};


/**
 * @brief Hardware pin mode configuration
 */

enum class PinMode : uint8_t {
	Unset = 0,          // High-impedance / Disconnected
	Input,              // Floating input
	InputPullup,        // Input with internal pull-up
	InputPulldown,      // Input with internal pull-down
	Output,             // Push-pull output
	OutputOpenDrain,    // Open-drain for shared buses
	InputOutput,        // Bidirectional mode
	AnalogInput,        // ADC mode
	AnalogOutput        // DAC mode
};

// =============================================================================
// 3. LOGIC AND POLARITY ABSTRACTION
// =============================================================================

/**
 * @brief Logical intent level
 */

enum class LogicLevel : uint8_t {
	Inactive = 0,
	Active   = 1
};

// EOF PinDefinitions.h



