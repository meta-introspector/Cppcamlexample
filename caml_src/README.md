This is where all of our OCaml source code goes.

Some notes:
* OCaml is, like Java, usually compiled to bytecode first
* that's exactly what we're doing, but we're compiling bytecode to an object file.
* the OCaml game code only has to deal with one structure handed across FFI boundaries - Engine::InputData
* include/ directory contains a C interface to the engine as well, for use by the FFI.
* the OCaml game code has full access to the engine library
