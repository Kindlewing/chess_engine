{
  pkgs ? import (fetchTarball {
    url = https://github.com/NixOS/nixpkgs-channels/archive/084445b8f38ff8196f4b3f16d0ad0e79aa88dcbc.tar.gz;
    sha256 = "0jqxx3csxbs32ijn8w6cbd9c3l9vvsjz57rqsyp44dgg37xxx00i";
  }) {}
}:
  with pkgs;
  stdenv.mkDerivation {
    name = "c-project";
    buildInputs = [ autoreconfHook ];
  }
