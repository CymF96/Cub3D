FROM ubuntu:latest

RUN apt-get update && apt-get install -y \
    libncurses5-dev \
    libreadline-dev \
    libbsd-dev \
    libx11-dev \
    libxkbfile-dev \
    build-essential \
    gdb \
    python3 \
    python3-pip \
    lcov \
    && rm -rf /var/lib/apt/lists/*

RUN pip3 install --upgrade pip setuptools --break-system-packages
RUN pip3 install norminette --break-system-packages

WORKDIR /usr/src/app

COPY . .

RUN make

CMD ["bash"]