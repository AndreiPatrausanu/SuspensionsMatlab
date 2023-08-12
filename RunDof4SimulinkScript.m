sim('ModelEquationsDOF4.slx');

XbDotDotSignal = yout.getElement('Xb_DOT_DOT');
XbDotDotValues = XbDotDotSignal.Values.Data;
RmsOfXbDotDot = GetRmsOf(XbDotDotValues) * 100; % because the values are too low

XbSignal = yout.getElement('Xb');
XbValues = XbSignal.Values.Data;
RmsOfXb = GetRmsOf(XbValues) * 100; % because the values are too low

save -ascii 'suspensionOutputDOF4.txt' RmsOfXb RmsOfXbDotDot