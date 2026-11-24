#!/usr/bin/env bash
# 2026-11-24, HTW_DEV, create a relocatable SDK tarball from install prefix
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")/../.." && pwd)"
BUILD_DIR="${ROOT_DIR}/build"
PREFIX="${ROOT_DIR}/install"
VERSION="$(tr -d '[:space:]' < "${ROOT_DIR}/VERSION")"
OUT="${ROOT_DIR}/packaging/tar/htwos-sdk-${VERSION}.tar.gz"

cmake --install "${BUILD_DIR}" --prefix "${PREFIX}"
tar -C "${PREFIX}" -czf "${OUT}" .
echo "Created ${OUT}"
