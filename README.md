# Self-Driving Car Project 10. Model Predictive Control (MPC)

## Overview

This project implements a [Model Predictive Controller (MPC)](https://en.wikipedia.org/wiki/Model_predictive_control) to control a car in the simulator (which can be downloaded [here](https://github.com/udacity/self-driving-car-sim/releases)). The simulator sends car telemetry information (here is the [data specifications](./DATA.md)) to the MPC using [WebSocket](https://en.wikipedia.org/wiki/WebSocket) and receives the steering angle and throttle from the MPC. The MPC uses the [uWebSockets](https://github.com/uNetworking/uWebSockets) WebSocket implementation to handle the communication.

## Dependencies

* cmake >= 3.5
 * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1(mac, linux), 3.81(Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools]((https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* [uWebSockets](https://github.com/uWebSockets/uWebSockets)
  * Run either `install-mac.sh` or `install-ubuntu.sh`.
  * If you install from source, checkout to commit `e94b6e1`, i.e.
    ```
    git clone https://github.com/uWebSockets/uWebSockets
    cd uWebSockets
    git checkout e94b6e1
    ```
    Some function signatures have changed in v0.14.x. See [this PR](https://github.com/udacity/CarND-MPC-Project/pull/3) for more details.

* **Ipopt and CppAD:** Please refer to [this document](https://github.com/udacity/CarND-MPC-Project/blob/master/install_Ipopt_CppAD.md) for installation instructions.
* [Eigen](http://eigen.tuxfamily.org/index.php?title=Main_Page). This is already part of the repo so you shouldn't have to worry about it.
* Simulator. You can download these from the [releases tab](https://github.com/udacity/self-driving-car-sim/releases).
* Not a dependency but read the [DATA.md](./DATA.md) for a description of the data sent back from the simulator.

## Build Instructions

1. Clone this repo
2. Make a build directory: `mkdir build && cd build`
3. Compile: `cmake .. && make`
4. Run it: `./mpc`

## Tips

1. It's recommended to test the MPC on basic examples to see if our implementation behaves as desired. One possible example
is the vehicle starting offset of a straight line (reference). If the MPC implementation is correct, after some number of timesteps
(not too many) it should find and track the reference line.
2. The `lake_track_waypoints.csv` file has the waypoints of the lake track. We could use this to fit polynomials and points and see of how well our model tracks curve. NOTE: This file might be not completely in sync with the simulator so our solution should NOT depend on it.
3. For visualization this C++ [matplotlib wrapper](https://github.com/lava/matplotlib-cpp) could be helpful.
4. Tips for setting up your environment are available [here](https://classroom.udacity.com/nanodegrees/nd013/parts/40f38239-66b6-46ec-ae68-03afd8a601c8/modules/0949fca6-b379-42af-a919-ee50aa304e6a/lessons/f758c44c-5e40-4e01-93b5-1a82aa4e044f/concepts/23d376c7-0195-4276-bdf0-e02f1f3c665d).

## Editor Settings

Here in this project, we use the following settings:
* Indent using spaces
* Set tab width to 4 spaces (keeps the matrices in source code aligned)

## Coding Style

Please (do our best to) stick to [Google's C++ style guide](https://google.github.io/styleguide/cppguide.html).

## Test the MPC

### Start the Simulator

Here is the start view of the simulator:

![Start View of the Simulator](./README-images/start.png)

(Note: Click the "Select" button to start the simulation.)

### Start the MPC Controller

Run the `./mpc`, and here is the output:
```
Listening to port 4567
Connected!!!
```

which means the our MPC has connected to the simulator successfully.

### Simulation

The MPC program can successfully drive the car for more than one lap around the track. And, this is a short video recording on the driving: [README-videos/MPC.mov](./README-videos/MPC.mov).

And, here is a snapshot on the execution log of the MPC program in the terminal:
```
... ...
_____________________
Data Received: [
    "telemetry",
    {
        "psi": 1.898499,
        "psi_unity": 5.955483,
        "ptsx": [
            126.8983,
            122.3383,
            117.2083,
            98.34827,
            83.63827,
            79.68355
        ],
        "ptsy": [
            -89.95898,
            -79.97897,
            -69.827,
            -42.02898,
            -20.72898,
            -12.66062
        ],
        "speed": 46.79108,
        "steering_angle": -0.04623421,
        "throttle": 0.5089387,
        "x": 124.8189,
        "y": -88.16193
    }
]

Cost: 32980.3

Data Sent: {
    "mpc_x": [
        9.34793806878252,
        14.0115901573713,
        18.6590152244839,
        23.2797874452453,
        27.8699917774771,
        32.4314831633189,
        36.9672611201617,
        41.478074583566
    ],
    "mpc_y": [
        0.379118647932027,
        0.87405638154702,
        1.54385646915663,
        2.40850635535663,
        3.44790339215663,
        4.6283269056966,
        5.92320917972555,
        7.32005290425031
    ],
    "next_x": [
        0.0,
        2.5,
        5.0,
        7.5,
        10.0,
        12.5,
        15.0,
        17.5,
        20.0,
        22.5,
        25.0,
        27.5,
        30.0,
        32.5,
        35.0,
        37.5,
        40.0,
        42.5,
        45.0,
        47.5,
        50.0,
        52.5,
        55.0,
        57.5,
        60.0
    ],
    "next_y": [
        -1.21831716203311,
        -1.0918269894696,
        -0.89974935102833,
        -0.645665934327369,
        -0.333158426984788,
        0.0341914833813414,
        0.452802109152949,
        0.919091762711964,
        1.42947875644032,
        1.98038140271993,
        2.56821801393275,
        3.18940690246068,
        3.84036638068567,
        4.51751476098964,
        5.21727035575453,
        5.93605147736225,
        6.67027643819475,
        7.41636355063395,
        8.17073112706177,
        8.92979747986015,
        9.68998092141102,
        10.4476997640963,
        11.1993723202979,
        11.9414169023978,
        12.6702518227779
    ],
    "steering_angle": -0.0322753902104054,
    "throttle": 0.546773239005437
}
... ...
```

## The MPC Implementation

### The MPC Model

The model used here for the MPC is a Kinematic model without considering the complex interactions between the tires and the road. The equations of this model are as follows:

```
x[t] = x[t-1] + v[t-1] * cos(psi[t-1]) * dt
y[t] = y[t-1] + v[t-1] * sin(psi[t-1]) * dt
psi[t] = psi[t-1] + v[t-1] / Lf * delta[t-1] * dt
v[t] = v[t-1] + a[t-1] * dt
cte[t] = f(x[t-1]) - y[t-1] + v[t-1] * sin(epsi[t-1]) * dt
epsi[t] = psi[t] - psides[t-1] + v[t-1] * delta[t-1] / Lf * dt
```

And here are the descriptions on the parameters:

#### Model State Parameters

These model state parameters are considered the state of the model:

| Model State Parameter | Description |
| :-------------------- | :---------- |
| `(x, y)` | Position of the car |
| `psi` | Heading direction of the car |
| `v` | Velocity of the car |
| `cte` | Cross-track error |
| `epsi` | Orientation error |

#### Constant Parameters

The constant parameter is provided by Udacity's courses and seed project:

| Constant Parameter | Description |
| :----------------- | :---------- |
| `Lf` | The distance between the mass and the front wheels of the car |

#### Model Output Parameters

These parameters are the output of the model:

| Model Output | Description |
| :----------- | :---------- |
| `a` | Acceleration (throttle) of the car |
| `delta` | Steering angle of the car |

#### Tuning the Acceleration and Steering Angle

The objective is to find the correct acceleration `a` and the steering angle `delta` which will minimize an objective function that is the combination of these different factors:

| Factor | Description |
| :----- | :---------- |
| Square sum of `cte` and `epsi` | See the code in [src/MPC.cpp](./src/MPC.cpp#L56) from line 56 to line 61 |
| Square sum of the difference actuators | To penalize actuator's actions, see the code in [src/MPC.cpp](./src/MPC.cpp#L64) from line 64 to line 68 |
| Square sum of the difference between two consecutive actuators | To penalize sharp changes, see the code in [src/MPC.cpp](./src/MPC.cpp#L72) from line 72 to line 76 |

The weights of all above factors are manually tuned so that we can successfully drive the car on the track without going off the road.

### Timestep Length and Elapsed Duration (N & dt)

The number of points `N` and the time interval `dt` define the prediction horizon. The number of points has an impact on the controller performance as well. I tried to keep the horizon around the same time the waypoints were on the simulator. With too many points the controller starts to run slower, and sometimes it went wild very easily. After trying with `N` from 10 to 20 and `dt` 100 to 500 milliseconds, I decided to leave them fixed to 10 and 100 milliseconds to have a better result tuning the other parameters.

### MPC Preprocessing and Polynomial Fitting

Here are the steps for the MPC preprocessing and polynomial fitting:

**Step 1**. Transform the waypoints (provided by the simulator) to the car coordinate system, see the code in [src/main.cpp](./src/main.cpp#L134) from line 134 to line 147

**Step 2**. Calculate the polynomial coefficients by fitting a third-degree polynomial to the transformed waypoints

**Step 3**. Calculate the `cte` and `epsi` using the polynomial coefficients

They are used by the solver as well to create a reference trajectory.

### MPC with Latency

There is a latency in the actuator, so we can't use the initial state values. In order to handle that, the state values are calculated using the model and the delay interval, which are used for later processing instead of the initial state values. See the code in [src/main.cpp](./src/main.cpp#L152) from line 152 to line 171.
