function DisplayArraySignal(array, graphTitle, yLabel)

    figure('Name',graphTitle,'NumberTitle','off')
    hold on
    title(graphTitle)
    ylabel(yLabel)
    plot(1:length(array), array,'b');
    hold off

end