#!/usr/bin/env bash 

set -Eeuxo pipefail

filename=${1:?"filename missing"}
g++ "${filename}" -I./include