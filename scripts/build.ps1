# 2026-11-24, HTW_DEV, configure and build HTWOS SDK on Windows
param(
    [string]$BuildType = "Release"
)

$ErrorActionPreference = "Stop"
$RootDir = Split-Path -Parent $PSScriptRoot
$BuildDir = Join-Path $RootDir "build"

if (-not (Get-Command cmake -ErrorAction SilentlyContinue)) {
    Write-Error "cmake not found. Install CMake and a C++20 toolchain first."
}

cmake -S $RootDir -B $BuildDir `
    -DCMAKE_BUILD_TYPE=$BuildType `
    -DHTWOS_SDK_BUILD_EXAMPLES=ON

cmake --build $BuildDir --config $BuildType --parallel
Write-Host "Build complete: $BuildDir"
