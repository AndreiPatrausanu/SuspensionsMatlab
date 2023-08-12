function DisplayScopeDataSignal(scopeData, graphTitle, yLabel)

    figure('Name', graphTitle, 'NumberTitle', 'off')
    hold on
    title(graphTitle)
    xlabel('Time [s]')
    ylabel(yLabel)
    plot(scopeData.time, scopeData.signals.values(:,1), 'b')
    hold off

end