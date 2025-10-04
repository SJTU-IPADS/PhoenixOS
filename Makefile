SRC_DIR := $(shell pwd)

IMAGE_NAME := phos-base-113
DOCKERFILE := $(SRC_DIR)/dockerfiles/build_113.Dockerfile

BUILD_ARGS ?= -i -3 -u -p=false
CLIENT_RUN_CMD ?= "python"

.PHONY: build clean exec

build-image:
	docker build \
		--build-arg proxy=http://ipads:ipads123@127.0.0.1:11235 \
		--progress=plain -f $(DOCKERFILE) -t $(IMAGE_NAME) . 

build: 
	docker run --rm --gpus all \
		-v $(SRC_DIR):/root \
		--privileged --network=host --ipc=host  \
		$(IMAGE_NAME) \
		bash -c "cd /root/scripts/build_scripts/ && bash build.sh $(BUILD_ARGS)"		

server-run:
	docker run --rm --gpus all -it \
		-v $(SRC_DIR):/root \
		--privileged --network=host --ipc=host  \
		$(IMAGE_NAME) \
		bash -c "CUDA_VISIBLE_DEVICES=2 pos_cli --start --target daemon"

client-run:
	docker run --rm --gpus all \
		-v $(SRC_DIR):/root \
		--privileged --network=host --ipc=host  \
		$(IMAGE_NAME) \
		bash -c "cd /root && export LD_LIBRARY_PATH=/root/lib:$LD_LIBRARY_PATH && export LIBRARY_PATH=/root/lib:$LIBRARY_PATH && LD_PRELOAD=/root/lib/libxpuclient.so RUST_LOG=error $(CLIENT_RUN_CMD)"		

clean: 
	docker run --rm --gpus all \
		-v $(SRC_DIR):/root \
		--privileged --network=host --ipc=host  \
		$(IMAGE_NAME) \
		bash -c "cd /root/scripts/build_scripts/ && bash build.sh -c -3"		

exec: 
	docker run --rm --gpus all -it \
		-v $(SRC_DIR):/root \
		--privileged --network=host --ipc=host  \
		$(IMAGE_NAME) \
		bash 		


