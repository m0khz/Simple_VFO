# m0khz-kicad-library
An atomic parts library for KiCad.

The goal of the m0khz-kicad-library library is to offer a collection of visually consistent and well defined parts that include assigned footprints.  The library is intended to augment KiCad's default library and give users another choice in library paradigm (meaning that it is *One Solution*, not *The Solution*).  It contains 1-to-1 symbol to footprint assignments to meet the needs of those who prefer that style.  It does not currently include the idea of a one symbol to many footprints as that defeats the purpose of having an orderable part number ready for the Bill of Materials.

Each part has been pre-loaded with extra information based on the www.digikey.com website.  Data includes:

- Manufacturer Part Number
- Manufacturer
- Category
- Family
- Datasheet Link
- Short Description
- Part Status (Active, Obsolete, NRND, etc)

This is an early release to help refine what this library to going be and solicit feedback on organizational philosophy. There are ongoing quality refinements, additions, and other work in the background.

The usable libraries are located in the `m0khz-footprints.pretty/` and `m0khz-symbols/` folders.

## Organization
 The intention is not to offer a complete library that includes all project parts, but to offer a useful subset which will grow over time.

Library metadata will be updated regularly and symbols for parts which may not be readily available will have its corresponding status appended to each symbol name.

## Installation

Standard practice - remember to link kicad symbols and footprints seperately :)


## Contributing
Please make pull requests against the footprints and symbols in the `src/` folder.  There is one part per .lib

## Licensing

The m0khz-kicad-library is licensed under a CC-BY-SA 4.0 license (with an exception) so please see the LICENSE.md for more information.


