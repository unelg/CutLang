default: root_image

all: root_image

# global build variables
ROOT_VERSION=6-26-04
PLATFORM="linux/amd64"
# TARGET_BRANCH may be a branch or a tag
TARGET_BRANCH="v${ROOT_VERSION}"
GIT_PROJECT_URL=https://github.com/root-project/root
ROOT_VERSION_SCM=$(subst -,.,$(ROOT_VERSION))

root_image:
	docker build . \
	-f Dockerfile \
	--platform "${PLATFORM}" \
	--build-arg PLATFORM=${PLATFORM} \
	--build-arg TARGET_BRANCH=$(TARGET_BRANCH) \
	--build-arg GIT_PROJECT_URL=$(GIT_PROJECT_URL) \
	--build-arg XROOTD_TAG=v5.4.3 \
	--build-arg ROOT_VERSION_SCM=$(ROOT_VERSION_SCM) \
	--tag cmsopendata/root-vnc:root$(ROOT_VERSION_SCM) \
	--tag cmsopendata/root-vnc:root$(ROOT_VERSION_SCM)-python3.10 \
	--tag cmsopendata/root-vnc



run_root_image:
	docker run --rm -it cmsopendata/root-vnc:latest
