{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.gcc       # C compiler
	pkgs.glibc
    pkgs.SDL2      # SDL library
    pkgs.SDL2_ttf  # SDL TTF library (optional, if you need TrueType font support)
    pkgs.SDL2_image # SDL image library (optional, if you need image loading support)
    pkgs.SDL2_mixer # SDL mixer library (optional, if you need sound mixing support)
  ];
}
