sim('ModelHalfCarDOF5.slx');

ZcDotDotSignal = yout.getElement('zc_DOT_DOT');
ZcDotDotValues = ZcDotDotSignal.Values.Data;
RmsOfZcDotDot = GetRmsOf(ZcDotDotValues) * 100; % because the values are too low

ZcSignal = yout.getElement('Zc');
ZcValues = ZcSignal.Values.Data;
RmsOfZc = GetRmsOf(ZcValues) * 100; % because the values are too low

save -ascii 'suspensionOutputDOF5.txt' RmsOfZc RmsOfZcDotDot