sim('ModelEquationsDOF2.slx');

XsDotDotSignal = yout.getElement('XsDotDot');
XsDotDotValues = XsDotDotSignal.Values.Data;
RmsOfXsDotDot = GetRmsOf(XsDotDotValues) * 100; % because the values are too low

XsSignal = yout.getElement('Xs');
XsValues = XsSignal.Values.Data;
RmsOfXs = GetRmsOf(XsValues) * 100; % because the values are too low

SwsSignal = yout.getElement('SWS');
SwsValues = SwsSignal.Values.Data;
RmsOfSws = GetRmsOf(SwsValues) * 100; % because the values are too low

save -ascii 'suspensionOutputDOF2.txt' RmsOfXs RmsOfXsDotDot RmsOfSws