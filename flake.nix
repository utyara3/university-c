{
  description = "Среда разработки для Си/C++ проектов";

  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs/nixos-unstable";
    utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, utils }:
    utils.lib.eachDefaultSystem (system:
      let
        pkgs = import nixpkgs { inherit system; };
      in
      {
        devShells.default = pkgs.mkShell {
          buildInputs = with pkgs; [
            gnumake
            gcc
            gdb
            valgrind
            clang-tools
          ];

          shellHook = ''
            echo "C/C++ development environment loaded"
          '';
        };
      });
}


