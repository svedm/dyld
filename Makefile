# Build dyld_closure_util with public macOS SDK
# Requires: Xcode with macOS SDK, git submodules initialized
#
# Usage:
#   make                    # build dyld_closure_util
#   make clean              # clean build artifacts
#   make test               # build and run a quick test
#
# First time setup:
#   git submodule update --init

.PHONY: all clean test closure_util

all: closure_util

closure_util:
	xcodebuild -project dyld.xcodeproj \
		-target dyld_closure_util \
		-configuration Debug \
		build \
		SDKROOT=macosx \
		VALID_ARCHS=arm64 \
		ARCHS=arm64
	@echo ""
	@echo "Built: build/Debug/dyld_closure_util"

clean:
	rm -rf build

test: closure_util
	@echo "=== dyld_closure_util usage ==="
	./build/Debug/dyld_closure_util
	@echo ""
	@echo "=== Listing closures in system dyld cache ==="
	./build/Debug/dyld_closure_util -list_dyld_cache_closures 2>&1 | head -20
