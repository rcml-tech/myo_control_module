#ifndef MYO_CONTROL_MODULE_H
#define	MYO_CONTROL_MODULE_H

class MyoControlModule : public ControlModule {
	myo::Hub* hub;
	myo::Myo* myo;
	DataCollector *myo_data_collector;

	AxisData *robot_axis;

	public:
		MyoControlModule();
		virtual int init();
		virtual AxisData* getAxis(int *count_axis);
		virtual void execute(sendAxisState_t sendAxisState);
		virtual void final();
		virtual void destroy();
		virtual ~MyoControlModule() {}
};

#define ADD_AXIS(AXIS_NAME, UPPER_VALUE, LOWER_VALUE) \
	robot_axis[axis_id].axis_index = axis_id + 1; \
	robot_axis[axis_id].upper_value = UPPER_VALUE; \
	robot_axis[axis_id].lower_value = LOWER_VALUE; \
	robot_axis[axis_id].name = AXIS_NAME; \
	axis_id++;

#endif	/* MYO_CONTROL_MODULE_H */