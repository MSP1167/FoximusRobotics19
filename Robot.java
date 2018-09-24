package org.usfirst.frc.team3695.robot;

import edu.wpi.first.wpilibj.IterativeRobot;


//        _____   _____   ____     ______
//       |__  /  / ___/  / __ \   / ____/
//        /_ <  / __ \  / /_/ /  /___ \
//      ___/ / / /_/ /  \__, /  ____/ /
//     /____/  \____/  /____/  /_____/
//
//       2018 - [fake robot name here]



/** the magic place where everything happens (where the sequence of events is controlled, top of the hierarchy) */
public class Robot extends IterativeRobot {
	
	/** runs when robot is turned on */
	public void robotInit() {}


	/** runs when autonomous starts */
	public void autonomousInit() {}

	/** runs at 50hz when in autonomous */
	public void autonomousPeriodic() {}



	/** runs when teleop starts*/
	public void teleopInit() {}

	/** runs at ~50hz when in teleop mode */
	public void teleopPeriodic() {}



	/** runs when test mode starts **/
	public void testInit() {}

	/** runs at ~50hz when in test mode */
	public void testPeriodic() {}



	/** runs when robot gets disabled */
	public void disabledInit() {}
	
	/** runs at 50hz when bot is disabled */
	public void disabledPeriodic() {}

}