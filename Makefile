# Build dyld tools with public macOS SDK
# Requires: Xcode with macOS SDK, git submodules initialized
#
# Usage:
#   make                    # build all tools
#   make closure_util       # build dyld_closure_util only
#   make inspect            # build dyld_inspect only
#   make clean              # clean build artifacts
#
# First time setup:
#   git submodule update --init

XCODEBUILD = xcodebuild -project dyld.xcodeproj -configuration Debug \
	SDKROOT=macosx VALID_ARCHS=arm64 ARCHS=arm64

TOOLS = closure_util inspect

.PHONY: all clean $(TOOLS)

all: $(TOOLS)

closure_util:
	$(XCODEBUILD) -target dyld_closure_util build
	@echo "\nBuilt: build/Debug/dyld_closure_util"

inspect:
	$(XCODEBUILD) -target dyld_inspect build
	@echo "\nBuilt: build/Debug/dyld_inspect"

clean:
	rm -rf build
