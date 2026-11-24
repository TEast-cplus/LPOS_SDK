#!/usr/bin/env bash
# 2026-11-24, HTW_DEV, configure and build HTWOS SDK on Linux
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"
BUILD_TYPE="${1:-Release}"

cmake -S "${ROOT_DIR}" -B "${BUILD_DIR}" \
  -DCMAKE_BUILD_TYPE="${BUILD_TYPE}" \
  -DHTWOS_SDK_BUILD_EXAMPLES=ON

cmake --build "${BUILD_DIR}" --parallel

echo "Build complete: ${BUILD_DIR}"
echo "Try: ${BUILD_DIR}/examples/native/hello_capability/htwos_hello_capability"
