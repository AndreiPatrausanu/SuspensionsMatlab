function rms = GetRmsOf(signal)

    sum = 0;

    for index = 1:size(signal)
        
        sum = sum + signal(index) * signal(index);

    end

    rms = sqrt(sum) / size(signal, 1);

end