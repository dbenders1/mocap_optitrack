# mocap_optitrack
This page explains how to setup a connection between the so-called *ROS computer* (your laptop) and the *OptiTrack computer* (the desktop receiving data from the OptiTrack cameras).



## Calibration (optional)
- Log into the *OptiTrack computer*
- Start *Motive*
- Select "perform new calibration"
- [Camera system calibration](https://v21.wiki.optitrack.com/index.php?title=Calibration):
    - Making, wandering, calibration results, ground plane and origin ...
    - (TODO: A picture showing our definition of the origin)
- Save the calibration file



## Data streaming
- Log into the *OptiTrack computer*
- Start *Motive*
- Create a new project or load a prior project
- Place the objects with markers attached in the workspace
- Define rigid objects within the workspace:
    - Select desired markers, right click and select "Create rigid body"
    - Assign a "User ID": for each object, which should match the configuration in the OptiTrack ROS package (described below)
- In the streaming panel:
    - Make sure the "Broadcast Frame Data" is selected
    - Make sure the type "MultiCast" is selected in Advanced Network Settings

> Note: if you cannot find those panels, click "View" in the menu bar of *Motive*, and choose "Project", "Data streaming". Then you should see those panels.



## Install the OptiTrack ROS package
- Log into the *ROS computer*
- Clone and build this *mocap_optitrack* ROS package, e.g.:
    ```
    cd catkin_ws/src
    git clone -b dcsc_pose_stamped git@github.com:tud-amr/mocap_optitrack.git
    cd ..
    catkin build mocap_optitrack
    source devel/setup.bash
    ```

> Note: the newest version of the original [mocap_optitrack](https://github.com/ros-drivers/mocap_optitrack) ROS package has some unsolved issues. See [mocap_optitrack ROS wiki page](http://wiki.ros.org/mocap_optitrack) for more information.



## Read mocap data
- Log into the *ROS computer*
- Check if the *ROS computer* is connected to the ROS network (WLAN connection is preferable)
- Run the launch file, e.g.:
    ```
    roslaunch mocap_optitrack hovergames.launch
    ```
- You can check if the data streaming is successful using the rostopic commands:
    ```
    rostopic list
    rostopic echo TOPIC_NAME
    ```
