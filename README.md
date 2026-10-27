# WinTune

WinTune is an early-stage C++ command-line project for exploring Windows system configuration and performance-related settings.

The aim is to explain what each setting changes and present available options before applying them, rather than offering unexplained “optimisation” presets or promising universal performance improvements.

## Current Features

- Windows Registry DWORD read/write functionality through a dedicated `RegistryProvider`.
- Class-based command-line interface with registry tweak menus.
- Structured tweak metadata, including descriptions, categories and risk information.
- Configurable options stored as a vector of structs, each containing a value, label and description.
- Display of the current registry value and a marker identifying the matching option.
- Individual option descriptions shown after selection.

The first setting being explored is **Win32PrioritySeparation**, which controls aspects of Windows CPU scheduling.

## In Progress

- Completing option selection and Apply/Back navigation.
- Connecting selected options to registry writes through the CLI.
- Improving input validation and error reporting.
- Simplifying menu control flow and separating screen responsibilities.

## Planned

Potential future additions include:

- Per-setting backup and rollback.
- Windows power plan configuration.
- Device power-saving settings.
- Restore point creation.
- Additional settings where their behaviour and trade-offs can be explained clearly.

## Design Approach

WinTune aims to distinguish documented behaviour from experimental changes. A setting is not treated as an improvement simply because it differs from the Windows default.

Performance effects can depend on the workload, hardware and Windows version. Alternative configurations should be measured against the original configuration rather than presented as universally better.

## Project Status

WinTune is a **very early-stage personal project**, developed alongside work and other commitments.

It is a practical way to develop my understanding of modern C++, the Win32 API, Windows internals and maintainable application design. Features and structure will continue to evolve as the project develops.
