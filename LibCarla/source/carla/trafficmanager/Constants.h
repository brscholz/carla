
/// This file contains various constants used in traffic manager
/// arranged into sensible namespaces for re-usability across
/// different files.

#pragma once

#include <limits>

#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define SQUARE(a) ((a) * (a))
#define RATE(MaxY, MinY, DiffX) (((MaxY) - (MinY)) / (DiffX))

namespace carla
{
namespace traffic_manager
{
namespace constants
{

namespace Networking
{
static unsigned int MIN_TRY_COUNT = 20u;
static unsigned short TM_DEFAULT_PORT = 8000u;
static unsigned int TM_TIMEOUT = 2000; // ms
} // namespace Networking

namespace VehicleRemoval
{
static const float STOPPED_VELOCITY_THRESHOLD = 0.8f;
static const float BLOCKED_TIME_THRESHOLD = 90.0f;
static const float DELTA_TIME_BETWEEN_DESTRUCTIONS = 10.0f;
} // namespace VehicleRemoval

namespace HybridMode
{
static const float HYBRID_MODE_DT = 0.05f;
static const float PHYSICS_RADIUS = 50.0f;
} // namespace HybridMode

namespace SpeedThreshold
{
static const float HIGHWAY_SPEED = 50.0f / 3.6f;
static const float ARBITRARY_MAX_SPEED = 100.0f / 3.6f;
} // namespace SpeedThreshold

namespace PathBufferUpdate
{
static const float MAX_START_DISTANCE = 30.0f;
static const float MINIMUM_HORIZON_LENGTH = 30.0f;
static const float MAXIMUM_HORIZON_LENGTH = 60.0f;
static const float HORIZON_RATE = RATE(MAXIMUM_HORIZON_LENGTH,
                                       MINIMUM_HORIZON_LENGTH,
                                       SpeedThreshold::ARBITRARY_MAX_SPEED);
} // namespace PathBufferUpdate

namespace WaypointSelection
{
static const float TARGET_WAYPOINT_TIME_HORIZON = 1.0f;
static const float TARGET_WAYPOINT_HORIZON_LENGTH = 2.5f;
static const float JUNCTION_LOOK_AHEAD = 10.0f; // m
} // namespace WaypointSelection

namespace LaneChange
{
static const float MINIMUM_LANE_CHANGE_DISTANCE = 10.0f;
static const float MAXIMUM_LANE_OBSTACLE_DISTANCE = 50.0f;
static const float MAXIMUM_LANE_OBSTACLE_CURVATURE = 0.6f;
static const float INTER_LANE_CHANGE_DISTANCE = 10.0f;
} // namespace LaneChange

namespace Collision
{
static const float BOUNDARY_EXTENSION_MAXIMUM = 50.0f;
static const float BOUNDARY_EXTENSION_MINIMUM = 2.0f;
static const float BOUNDARY_EXTENSION_RATE = RATE(BOUNDARY_EXTENSION_MAXIMUM,
                                                  BOUNDARY_EXTENSION_MINIMUM,
                                                  SpeedThreshold::ARBITRARY_MAX_SPEED);
static const float COS_10_DEGREES = 0.9848f;
static const float EPSILON_VELOCITY = 0.1f;
static const float LOCKING_DISTANCE_PADDING = 4.0f;
static const float MAX_COLLISION_RADIUS = 100.0f;
static const float MAX_LOCKING_EXTENSION = 10.0f;
static const float WALKER_TIME_EXTENSION = 1.5f;
static const float SQUARE_ROOT_OF_TWO = 1.414f;
static const float VERTICAL_OVERLAP_THRESHOLD = 4.0f;
} // namespace Collision

namespace FrameMemory
{
static const unsigned int INITIAL_SIZE = 50u;
static const unsigned int GROWTH_STEP_SIZE = 50u;
} // namespace FrameMemory

namespace Map
{
static const float INFINITE_DISTANCE = std::numeric_limits<float>::max();
static const float GRID_SIZE = 4.0f;
static const float PED_GRID_SIZE = 10.0f;
static const float MAX_GEODESIC_GRID_LENGTH = 20.0f;
static const float MAP_RESOLUTION = 0.1f;
} // namespace Map

namespace TrafficLight
{
static const unsigned int NO_SIGNAL_PASSTHROUGH_INTERVAL = 5u;
} // namespace TrafficLight

namespace MotionPlan
{
static const float RELATIVE_APPROACH_SPEED = 10.0f / 3.6f;
static const float MIN_FOLLOW_LEAD_DISTANCE = 5.0f;
static const float MAX_FOLLOW_LEAD_DISTANCE = 10.0f;
static const float FOLLOW_DISTANCE_RATE = RATE(MAX_FOLLOW_LEAD_DISTANCE,
                                               MIN_FOLLOW_LEAD_DISTANCE,
                                               SpeedThreshold::ARBITRARY_MAX_SPEED);
static const float CRITICAL_BRAKING_MARGIN = 0.25f;
static const float EPSILON_RELATIVE_SPEED = 0.001f;
} // namespace MotionPlan

namespace PID
{
static const float MAX_THROTTLE = 0.7f;
static const float MAX_BRAKE = 1.0f;
static const float VELOCITY_INTEGRAL_MAX = 5.0f;
static const float VELOCITY_INTEGRAL_MIN = -5.0f;
static const float DT = 1.0f/20.0f;
}

} // namespace constants
} // namespace traffic_manager
} // namespace carla
