{
  description = "";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = nixpkgs.legacyPackages.${system};
      in rec {
        devShell = pkgs.mkShell rec {
          buildInputs = with pkgs; [
            # compilation
			SDL2
			SDL2.dev
            meson
            ninja
            gccStdenv
            gcc
            # need clang tools for vscode I think
            clang
            clang-tools

            # libraries
            libllvm
          ];
          LD_LIBRARY_PATH = "${pkgs.lib.makeLibraryPath buildInputs}";
        };
      });
}
