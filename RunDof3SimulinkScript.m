sim('ModelEquationsDOF3.slx');

ZsSignal = yout.getElement('Zs');
ZsValues = ZsSignal.Values.Data;
RmsOfZs = GetRmsOf(ZsValues) * 100; % because the values are too low

ZsDotDotSignal = yout.getElement('ZsDotDot');
ZsDotDotValues = ZsDotDotSignal.Values.Data;
RmsOfZsDotDot = GetRmsOf(ZsDotDotValues) * 100; % because the values are too low

save -ascii 'suspensionOutputDOF3.txt' RmsOfZs RmsOfZsDotDot