ClearAllWindows();

LoadRoadScript;
DisplayArraySignal(road_front_wheel, 'Random road', 'Elevation [mm]');

DOF = input('Type DOF number - 2, 3, 4 or 5 : ');

if DOF == 2 

    ModelFixedParamDOF2;
    OptimizedParamDOF2;

    RunDof2SimulinkScript;

    open_system('ModelEquationsDOF2.slx');
 
    DisplayScopeDataSignal(Xs_ScopeData, 'Displacement - Xs', 'Displacement [m]');
    DisplayScopeDataSignal(XsDot_ScopeData, 'Velocity - XsDot', 'Velocity [m/s]');
    DisplayScopeDataSignal(XsDotDot_ScopeData, 'Acceleration - XsDotDot', 'Acceleration - [m/s^2]');
    DisplayScopeDataSignal(SWS_ScopeData, 'SWS - |Xs - Xu|', 'SWS [m]');
    
    disp('DOF2 DONE');

elseif DOF == 3

    ModelFixedParamDOF3;
    OptimizedParamDOF3;

    RunDof3SimulinkScript;

    open_system('ModelEquationsDOF3.slx');
    
    DisplayScopeDataSignal(Zs_ScopeData, 'Displacement - Zs', 'Displacement [m]');
    DisplayScopeDataSignal(ZsDot_ScopeData, 'Velocity - ZsDot', 'Velocity [m/s]');
    DisplayScopeDataSignal(ZsDotDot_ScopeData, 'Acceleration - ZsDotDot', 'Acceleration - [m/s^2]');
    DisplayScopeDataSignal(SWS_ScopeData, 'SWS - SWS - |Zc - Zt|', 'SWS [m]');

    disp('DOF3 DONE');

elseif DOF == 4

    ModelFixedParamDOF4;
    OptimizedParamDOF4;

    RunDof4SimulinkScript;

    open_system('ModelEquationsDOF4.slx');

    DisplayScopeDataSignal(Xb_ScopeData, 'Displacement - Xb', 'Displacement [m]');
    DisplayScopeDataSignal(Xb_DOT_ScopeData, 'Velocity - XbDot', 'Velocity [m/s]');
    DisplayScopeDataSignal(Xb_DOT_DOT_ScopeData, 'Acceleration - XbDotDot', 'Acceleration - [m/s^2]');
    DisplayScopeDataSignal(SWS_ScopeData, 'SWS - |Xb - Xu|', 'SWS [m]');

    disp('DOF4 DONE');

elseif DOF == 5

    ModelFixedParamDOF5;
    OptimizedParamDOF5;

    RunDof5SimulinkScript;
    
    open_system('ModelHalfCarDOF5.slx');

    DisplayScopeDataSignal(Zc_ScopeData, 'Displacement - Zc', 'Displacement [m]');
    DisplayScopeDataSignal(Zc_DOT_ScopeData, 'Velocity - ZcDot', 'Velocity [m/s]');
    DisplayScopeDataSignal(Zc_DOT_DOT_ScopeData, 'Acceleration - ZcDotDot', 'Acceleration - [m/s^2]');
    DisplayScopeDataSignal(sws_ScopeData, 'SWS - |Zs1 - Z1|', 'SWS [m]');

    disp('DOF5 DONE');
else
    disp('Only DOF numbers 2,3,4 or 5 are available.');
end