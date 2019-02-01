//
// Created by syue on 19-2-1.
//

#include "device.h"
#include "boost/assign.hpp"
#include "mode.h"
#include <sound_play/SoundRequest.h>
typedef enum {
	VOICE_NULL						= 0,
	VOICE_WELCOME_ILIFE				= 1,
	VOICE_PLEASE_START_CLEANING		= 2,
	VOICE_CLEANING_FINISHED			= 3,
	VOICE_CLEANING_START				= 4,
	VOICE_CLEANING_WALL_FOLLOW		= 5,
	VOICE_GO_HOME_MODE				= 6,
	VOICE_CLEANING_SPOT				= 7,
	VOICE_VACUUM_NORMAL			= 8,
	VOICE_APPOINTMENT_DONE			= 9,
	VOICE_VACCUM_MAX					= 10,
	VOICE_BATTERY_LOW					= 11,
	VOICE_BATTERY_CHARGE				= 12,
	VOICE_BATTERY_CHARGE_DONE			= 13,
	VOICE_ERROR_RUBBISH_BIN			= 14,
	VOICE_CLEAN_RUBBISH_BIN			= 15,
	VOICE_ERROR_LEFT_BRUSH			= 16,
	VOICE_ERROR_RIGHT_BRUSH			= 17,
	VOICE_ERROR_LEFT_WHEEL			= 18,
	VOICE_ERROR_RIGHT_WHEEL			= 19,
	VOICE_ERROR_MAIN_BRUSH			= 20,
	VOICE_ERROR_SUCTION_FAN			= 21,
	VOICE_ERROR_BUMPER				= 22,
	VOICE_ERROR_CLIFF					= 23,
	VOICE_ERROR_MOBILITY_WHEEL		= 24,
	VOICE_ERROR_LIFT_UP				= 25,
	VOICE_TEST_MODE					= 26,
	VOICE_CAMERA_CALIBRATION_MODE		= 27,
	VOICE_TEST_MODE_IEC				= 28,
	VOICE_CAMERA_CALIBRATION_START	= 29,
	VOICE_CAMERA_CALIBRATION_SUCCESS	= 30,
	VOICE_CAMERA_CALIBRATION_FAIL		= 31,
	VOICE_TEST_SUCCESS				= 32,
	VOICE_TEST_FAIL					= 33,
	VOICE_WIFI_CONNECTING				= 34,
	VOICE_WIFI_CONNECTED				= 35,
	VOICE_ERROR_LIDAR					= 36,
	VOICE_CLEANING_CONTINUE			= 37,
	VOICE_SYSTEM_INITIALIZING			= 38,
	VOICE_BACK_TO_CHARGER_FAILED		= 39,
	VOICE_CLEANING_PAUSE				= 40,
	VOICE_CLEAR_ERROR_UNOFFICIAL					= 41,
	VOICE_CANCEL_APPOINTMENT_UNOFFICIAL			= 42,
	VOICE_APPOINTMENT_START_UNOFFICIAL			= 43,
	VOICE_CLEANING_STOP				= 44,
	VOICE_CHECK_SWITCH				= 45,
	VOICE_ROBOT_TRAPPED					= 46,
	VOICE_EXPLORATION_START_UNOFFICIAL			= 47,
	VOICE_ERROR_LIFT_UP_CANCEL_APPOINTMENT_UNOFFICIAL	=	48,
	VOICE_BATTERY_LOW_CANCEL_APPOINTMENT_UNOFFICIAL	=	49,
	VOICE_ERROR_LIFT_UP_CLEANING_STOP_UNOFFICIAL	=	50,
	VOICE_COPYING_LOG_UNOFFICIAL = 51,
	VOICE_COPYING_LOG_SUCCESS_UNOFFICIAL = 52,
	VOICE_COPYING_LOG_FAIL_UNOFFICIAL = 53,
	VOICE_PROCESS_ERROR_UNOFFICIAL				= 54,
	VOICE_USER_KILL_UNOFFICIAL					= 55,
	VOICE_WIFI_UNCONNECTED_UNOFFICIAL = 56,
	VOICE_WIFI_UNBIND_UNOFFICIAL = 57,
	VOICE_WIFI_SMART_LINK_UNOFFICIAL = 58,
	VOICE_CLOUD_CONNECTED_UNOFFICIAL = 59,
	VOICE_CLOUD_UNCONNECTED_UNOFFICIAL = 60,
	VOICE_SOFTWARE_VERSION_UNOFFICIAL	= 61,
	VOICE_IM_HERE_UNOFFICIAL = 62,
	VOICE_CONVERT_TO_LARGE_SUCTION_UNOFFICIAL= 63,
	VOICE_CONVERT_TO_NORMAL_SUCTION_UNOFFICIAL= 64,
	VOICE_FAILED_TO_FIND_CHARGEER_UNOFFICIAL = 65,
	VOICE_END_TO_FIND_CHARGEER_UNOFFICIAL = 66,
	VOICE_CLEANING_FINISH_BACK_TO_CHARGER = 67,
	VOICE_PLEASE_PULL_OUT_THE_PLUG = 68,
	VOICE_VALID_CMD_UNOFFICIAL = 69,
	VOICE_INVALID_CMD_UNOFFICIAL = 70,
	VOICE_WAKE_UP_UNOFFICIAL = 71,
	VOICE_SLEEP_UNOFFICIAL = 72,
	VOICE_GYRO_ERROR = 73,
	VOICE_FIND_ROBOT = 74,
	VOICE_END = 75,
}VoiceType;

void Device::normalClean() {
    ROS_INFO("Open");
}

void Device::idle() {
    ROS_INFO("Close");
}

void Vaccum::normalClean() {
    ROS_INFO("Vaccum Open");
}

void Vaccum::idle() {
    ROS_INFO("Vaccum idle");
}

void Vaccum::spotClean() {
    ROS_INFO("Vaccum spotClean");
}

void Brush::normalClean() {
    ROS_INFO("Brush normalClean");
}
void Brush::idle() {
    ROS_INFO("Brush idle");
}

void Brush::spotClean() {
    ROS_INFO("Brush spotClean");
}

void WaterTank::normalClean() {
    ROS_INFO("WaterTank normalClean");
}

void WaterTank::idle() {
    ROS_INFO("WaterTank idle");
}

void WaterTank::spotClean() {
    ROS_INFO("WaterTank spotClean");
}

void Speaker::normalClean() {
    ROS_INFO("Speaker normalClean");
    sound_play::SoundRequest msg;
    msg.sound = sound_play::SoundRequest::PLAY_FILE;
    msg.command = sound_play::SoundRequest::PLAY_ONCE;
	msg.volume = 0.5;
    msg.arg = "/home/syue/catkin_ws/src/syue_robot/path_plan/audio_cn/04.wav";
    speaker_pub_.publish(msg);
}

void Speaker::idle() {
    ROS_INFO("Speaker idle");
    sound_play::SoundRequest msg;
    msg.sound = sound_play::SoundRequest::PLAY_FILE;
    msg.command = sound_play::SoundRequest::PLAY_ONCE;
    msg.volume = 0.5;
    msg.arg = "/home/syue/catkin_ws/src/syue_robot/path_plan/audio_cn/03.wav";
    speaker_pub_.publish(msg);
}

void Speaker::spotClean() {
    ROS_INFO("Speaker spotClean");
    sound_play::SoundRequest msg;
    msg.sound = sound_play::SoundRequest::PLAY_FILE;
    msg.command = sound_play::SoundRequest::PLAY_ONCE;
	msg.volume = 0.5;
    msg.arg = "/home/syue/catkin_ws/src/syue_robot/path_plan/audio_cn/07.wav";
    speaker_pub_.publish(msg);
}

Speaker::Speaker() {
    ros::NodeHandle nh;
    speaker_pub_ = nh.advertise<sound_play::SoundRequest>("/robotsound",1);;
}

Devices::Devices() {
    using namespace boost::assign;
    devices_ += new WaterTank,new Brush, new Vaccum, new Speaker;
}

void Devices::action()const {

}

void Devices::idle() {
    for(auto&& dev:devices_)
    {
        dev->idle();
    }
}

void Devices::normalClean() {
    for(auto&& dev:devices_)
    {
        dev->normalClean();
    }
}
void Devices::spotClean() {
    for(auto&& dev:devices_)
    {
        dev->normalClean();
    }
}
void Devices::followWallClean() {
    for(auto&& dev:devices_)
    {
        dev->normalClean();
    }
}
