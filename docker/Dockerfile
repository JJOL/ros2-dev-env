FROM mcr.microsoft.com/devcontainers/cpp:0-ubuntu-20.04

ENV JAVA_VERSION="11"

# install all dependencies
ENV DEBIAN_FRONTEND="noninteractive"
# Install Pip
RUN apt-get update \
    && apt-get install -y python3-pip
RUN pip install --upgrade pip

#Install Noetic ROS1 and Tools
RUN echo "deb http://packages.ros.org/ros/ubuntu focal main" | sudo tee /etc/apt/sources.list.d/ros-focal.list 
RUN sudo apt-key adv --keyserver 'hkp://keyserver.ubuntu.com:80' --recv-key C1CF6E31E6BADE8868B172B4F42ED6FBAB17C654

# Install ROS 2 Galactic
RUN echo "deb [arch=amd64 signed-by=/usr/share/keyrings/ros-archive-keyring.gpg] http://packages.ros.org/ros2/ubuntu focal main" | sudo tee /etc/apt/sources.list.d/ros2.list > /dev/null
RUN sudo curl -sSL https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -o /usr/share/keyrings/ros-archive-keyring.gpg

# Install Apt Packages
COPY apt-packages /tmp/
RUN apt-get update && \
    apt-get install -y \
        $(cat /tmp/apt-packages | cut -d# -f1 | envsubst) \
    && rm -rf /var/lib/apt/lists/* /tmp/apt-packages

# Install Pip Packages
COPY pip3-packages /tmp/
RUN pip3 install -U \
        $(cut -d# -f1 </tmp/pip3-packages) \
    && rm -rf /root/.cache /tmp/pip-* /tmp/pip3-packages

## Setting up Dev Visualization Tools
#RUN source /opt/ros/galactic/setup.bash
RUN export GAZEBO_IP=127.0.0.1
RUN export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0 
RUN export LIBGL_ALWAYS_INDIRECT=0

# Install Galactic desktop
RUN sudo apt update && \
    sudo apt install -y ros-galactic-desktop
# Install colcon
RUN sudo apt update && \
    sudo apt install -y python3-colcon-common-extensions python3-rosdep python3-vcstool
# Installing ros1_bridge
#RUN sudo apt install ros-<ros2-distro>-ros1_bridge

# Installing Nav2
#RUN sudo apt install ros-<ros2-distro>-navigation2
#RUN sudo apt install ros-<ros2-distro>-nav2-bringup


#Entrypoint and Ownership
COPY entrypoint.sh /usr/local/bin/
COPY chown.sh /usr/local/bin/

COPY ./reinstall-cmake.sh /tmp/

RUN if [ "${REINSTALL_CMAKE_VERSION_FROM_SOURCE}" != "none" ]; then \
        chmod +x /tmp/reinstall-cmake.sh && /tmp/reinstall-cmake.sh ${REINSTALL_CMAKE_VERSION_FROM_SOURCE}; \
    fi \
    && rm -f /tmp/reinstall-cmake.sh

ENTRYPOINT [ "/usr/local/bin/entrypoint.sh" ]
