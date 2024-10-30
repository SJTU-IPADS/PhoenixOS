## Third-parties Dependencies of PhoenixOS

PhoenixOS uses the following projects as third parties, we thank all their authors.

1. `libclang-static-build`

    PhoenixOS `libclang` for parsing the signature of kernels, and we also use it for auto-generating code of parsers and workers. Note that this repo is from [deech/libclang-static-build](https://github.com/deech/libclang-static-build), we conducted some modification on it, so we cast it as part of local repository instead of submodule here.

2. `criu`

    PhoenixOS leverages CRIU to checkpoint and restore the program state on CPU side. Currently we're maintaining our downstream at <a href="https://github.com/SJTU-IPADS/PhoenixOS-CRIU">SJTU-IPADS/PhoenixOS-CRIU</a>.

3. `googletest`

    PhoenixOS uses GoogleTest framework to conduct unit test of the system components.

4. `protobuf`

    PhoenixOS uses protobuf to serialize/deserialize the checkpointed image.

5. `yaml-cpp`

    PhoenixOS uses `yaml-cpp` for parsing configurations when auto-generating code of parsers and workers.
