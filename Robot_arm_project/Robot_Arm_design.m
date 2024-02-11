classdef Robot_Arm_design < matlab.apps.AppBase

    % Properties that correspond to app components
    properties (Access = public)
        UIFigure                      matlab.ui.Figure
        GridLayout                    matlab.ui.container.GridLayout
        LeftPanel                     matlab.ui.container.Panel
        simulationButton              matlab.ui.control.Button
        lengtharm_1mEditFieldLabel    matlab.ui.control.Label
        lengtharm_1mEditField         matlab.ui.control.NumericEditField
        lengtharm_2mEditFieldLabel    matlab.ui.control.Label
        lengtharm_2mEditField         matlab.ui.control.NumericEditField
        controlthelengthofarmsLabel   matlab.ui.control.Label
        for360degreemotionLabel       matlab.ui.control.Label
        numofloopsforarm_2EditFieldLabel  matlab.ui.control.Label
        numofloopsforarm_2EditField   matlab.ui.control.NumericEditField
        CenterPanel                   matlab.ui.container.Panel
        UIAxes                        matlab.ui.control.UIAxes
        Switch                        matlab.ui.control.Switch
        RightPanel                    matlab.ui.container.Panel
        lengtharm_1mEditField_2Label  matlab.ui.control.Label
        lengtharm_1mEditField_2       matlab.ui.control.NumericEditField
        lengtharm_2mEditField_2Label  matlab.ui.control.Label
        lengtharm_2mEditField_2       matlab.ui.control.NumericEditField
        anglearm_1DSlider_3Label      matlab.ui.control.Label
        anglearm_1DSlider_3           matlab.ui.control.Slider
        anglearm_2DSliderLabel        matlab.ui.control.Label
        anglearm_2DSlider             matlab.ui.control.Slider
        controlthelenghtofarmsLabel   matlab.ui.control.Label
        andtheanglesLabel             matlab.ui.control.Label
        simulationButton_2            matlab.ui.control.Button
    end

    % Properties that correspond to apps with auto-reflow
    properties (Access = private)
        onePanelWidth = 576;
        twoPanelWidth = 768;
    end

    % Callbacks that handle component events
    methods (Access = private)

        % Button pushed function: simulationButton
        function simulationButtonPushed(app, event)

hold(app.UIAxes, "off");
%fixed origin points
x_orgin=0;
y_orgin=0;

% the legths of the arms
length_first_arm = app.lengtharm_1mEditField.Value ;
length_2th_arm = app.lengtharm_2mEditField.Value;
loops_num= app.numofloopsforarm_2EditField.Value;
% the range of the angles of arms
angle_first_arm=linspace(0,180,200);
angle_2th_arm=linspace(0,loops_num*360,200);

% the equations of the system

y1=length_first_arm*sind(angle_first_arm);
x1=length_first_arm*cosd(angle_first_arm);
y2=length_2th_arm*sind(angle_2th_arm+angle_first_arm)+y1;
x2=length_2th_arm*cosd(angle_2th_arm+angle_first_arm)+x1;

% plots to be deleted in the loop to delete the old plot and dram the new
first_plot = plot(app.UIAxes,[x_orgin,0],[y_orgin,0],'LineWidth',7,'Color','r')
hold(app.UIAxes, "on");
secend_plot = plot(app.UIAxes,[0,0],[0,0],'LineWidth',8,'Color','b')

% the ranges of x,y axis
xlim(app.UIAxes,[-length_first_arm*2,length_first_arm*2])
ylim(app.UIAxes,[-length_2th_arm*2,length_2th_arm*2])

% to draw every plot in the loop in the same figure
%hold on
grid on

%to get the shape of the 2th arm moves
plot(app.UIAxes,x2, y2)

% the loop to display the motion graphic of the arms
for i=1:length(angle_first_arm)
  % delete the old graph   
  delete(first_plot);
  delete(secend_plot);
  
  %plot the new graph
  first_plot=plot(app.UIAxes,[x_orgin,x1(i)],[y_orgin,y1(i)],'LineWidth',7,'Color','r')
  secend_plot=plot(app.UIAxes,[x1(i),x2(i)],[y1(i),y2(i)],'LineWidth',5,'Color','b')

  
  % to show the new graph not only the last one
  drawnow
 
  % pause function to control the time of every graph
  %pause(.05);
end

  
        
        end

        % Button pushed function: simulationButton_2
        function simulationButton_2Pushed(app, event)
            
hold(app.UIAxes, "off");
x0=0;
y0=0;

length_first_arm=app.lengtharm_1mEditField_2.Value;
length_2th_arm=app.lengtharm_2mEditField_2.Value;

angle_first_arm=app.anglearm_1DSlider_3.Value;
angle_2th_arm=app.anglearm_2DSlider.Value;

len_theta_1=linspace(0,angle_first_arm,50);
len_theta_2=linspace(0,angle_2th_arm,50);

y1 = times(length_first_arm,sind(len_theta_1));
x1 = times(length_first_arm,cosd(len_theta_1));
y2 = times(length_2th_arm,sind(len_theta_2)+y1);
x2 = times(length_2th_arm,cosd(len_theta_2)+x1);

first = plot(app.UIAxes, [x0,0],[y0,0],'LineWidth',4,'Color','r')
hold(app.UIAxes, "on");
secend = plot(app.UIAxes, [0,0],[0,0],'LineWidth',5,'Color','b')
hold on
grid on
xlim(app.UIAxes, [-length_first_arm*3,length_first_arm*3])
ylim(app.UIAxes, [-length_2th_arm*2,length_2th_arm*2])
plot(app.UIAxes, x2, y2)
for i=1:1:length(len_theta_1)
    

  delete(first);
  delete(secend);
  first = plot(app.UIAxes, [x0,x1(i)],[y0,y1(i)],'LineWidth',4,'Color','r')
  secend = plot(app.UIAxes, [x1(i),x2(i)],[y1(i),y2(i)],'LineWidth',5,'Color','b')
  drawnow
   % pause(.01);
end
            
        end

        % Changes arrangement of the app based on UIFigure width
        function updateAppLayout(app, event)
            currentFigureWidth = app.UIFigure.Position(3);
            if(currentFigureWidth <= app.onePanelWidth)
                % Change to a 3x1 grid
                app.GridLayout.RowHeight = {482, 482, 482};
                app.GridLayout.ColumnWidth = {'1x'};
                app.CenterPanel.Layout.Row = 1;
                app.CenterPanel.Layout.Column = 1;
                app.LeftPanel.Layout.Row = 2;
                app.LeftPanel.Layout.Column = 1;
                app.RightPanel.Layout.Row = 3;
                app.RightPanel.Layout.Column = 1;
            elseif (currentFigureWidth > app.onePanelWidth && currentFigureWidth <= app.twoPanelWidth)
                % Change to a 2x2 grid
                app.GridLayout.RowHeight = {482, 482};
                app.GridLayout.ColumnWidth = {'1x', '1x'};
                app.CenterPanel.Layout.Row = 1;
                app.CenterPanel.Layout.Column = [1,2];
                app.LeftPanel.Layout.Row = 2;
                app.LeftPanel.Layout.Column = 1;
                app.RightPanel.Layout.Row = 2;
                app.RightPanel.Layout.Column = 2;
            else
                % Change to a 1x3 grid
                app.GridLayout.RowHeight = {'1x'};
                app.GridLayout.ColumnWidth = {244, '1x', 250};
                app.LeftPanel.Layout.Row = 1;
                app.LeftPanel.Layout.Column = 1;
                app.CenterPanel.Layout.Row = 1;
                app.CenterPanel.Layout.Column = 2;
                app.RightPanel.Layout.Row = 1;
                app.RightPanel.Layout.Column = 3;
            end
        end
    end

    % Component initialization
    methods (Access = private)

        % Create UIFigure and components
        function createComponents(app)

            % Create UIFigure and hide until all components are created
            app.UIFigure = uifigure('Visible', 'off');
            app.UIFigure.AutoResizeChildren = 'off';
            app.UIFigure.Position = [100 100 904 482];
            app.UIFigure.Name = 'MATLAB App';
            app.UIFigure.SizeChangedFcn = createCallbackFcn(app, @updateAppLayout, true);

            % Create GridLayout
            app.GridLayout = uigridlayout(app.UIFigure);
            app.GridLayout.ColumnWidth = {244, '1x', 250};
            app.GridLayout.RowHeight = {'1x'};
            app.GridLayout.ColumnSpacing = 0;
            app.GridLayout.RowSpacing = 0;
            app.GridLayout.Padding = [0 0 0 0];
            app.GridLayout.Scrollable = 'on';

            % Create LeftPanel
            app.LeftPanel = uipanel(app.GridLayout);
            app.LeftPanel.BackgroundColor = [0.851 0.3255 0.098];
            app.LeftPanel.HandleVisibility = 'off';
            app.LeftPanel.Layout.Row = 1;
            app.LeftPanel.Layout.Column = 1;

            % Create simulationButton
            app.simulationButton = uibutton(app.LeftPanel, 'push');
            app.simulationButton.ButtonPushedFcn = createCallbackFcn(app, @simulationButtonPushed, true);
            app.simulationButton.BackgroundColor = [0.9294 0.6902 0.1294];
            app.simulationButton.FontColor = [0.6353 0.0784 0.1843];
            app.simulationButton.Position = [78 111 100 22];
            app.simulationButton.Text = 'simulation';

            % Create lengtharm_1mEditFieldLabel
            app.lengtharm_1mEditFieldLabel = uilabel(app.LeftPanel);
            app.lengtharm_1mEditFieldLabel.BackgroundColor = [0.851 0.3255 0.098];
            app.lengtharm_1mEditFieldLabel.HorizontalAlignment = 'right';
            app.lengtharm_1mEditFieldLabel.FontColor = [1 1 0];
            app.lengtharm_1mEditFieldLabel.Position = [17 338 92 19];
            app.lengtharm_1mEditFieldLabel.Text = 'length arm_1(m)';

            % Create lengtharm_1mEditField
            app.lengtharm_1mEditField = uieditfield(app.LeftPanel, 'numeric');
            app.lengtharm_1mEditField.RoundFractionalValues = 'on';
            app.lengtharm_1mEditField.HandleVisibility = 'off';
            app.lengtharm_1mEditField.BackgroundColor = [0.0706 0.6196 1];
            app.lengtharm_1mEditField.Position = [119 336 108 22];
            app.lengtharm_1mEditField.Value = 1;

            % Create lengtharm_2mEditFieldLabel
            app.lengtharm_2mEditFieldLabel = uilabel(app.LeftPanel);
            app.lengtharm_2mEditFieldLabel.HorizontalAlignment = 'right';
            app.lengtharm_2mEditFieldLabel.FontColor = [1 1 0];
            app.lengtharm_2mEditFieldLabel.Position = [22 294 97 22];
            app.lengtharm_2mEditFieldLabel.Text = 'length arm_2 (m)';

            % Create lengtharm_2mEditField
            app.lengtharm_2mEditField = uieditfield(app.LeftPanel, 'numeric');
            app.lengtharm_2mEditField.BackgroundColor = [0.0706 0.6196 1];
            app.lengtharm_2mEditField.Position = [124 294 108 22];
            app.lengtharm_2mEditField.Value = 1;

            % Create controlthelengthofarmsLabel
            app.controlthelengthofarmsLabel = uilabel(app.LeftPanel);
            app.controlthelengthofarmsLabel.FontName = 'Arial Black';
            app.controlthelengthofarmsLabel.FontSize = 15;
            app.controlthelengthofarmsLabel.FontColor = [1 1 0];
            app.controlthelengthofarmsLabel.Position = [11 438 221 23];
            app.controlthelengthofarmsLabel.Text = 'control the length of arms';

            % Create for360degreemotionLabel
            app.for360degreemotionLabel = uilabel(app.LeftPanel);
            app.for360degreemotionLabel.FontName = 'Arial Black';
            app.for360degreemotionLabel.FontSize = 15;
            app.for360degreemotionLabel.FontColor = [1 1 0];
            app.for360degreemotionLabel.Position = [34 403 187 23];
            app.for360degreemotionLabel.Text = 'for 360 degree motion';

            % Create numofloopsforarm_2EditFieldLabel
            app.numofloopsforarm_2EditFieldLabel = uilabel(app.LeftPanel);
            app.numofloopsforarm_2EditFieldLabel.HorizontalAlignment = 'right';
            app.numofloopsforarm_2EditFieldLabel.FontColor = [1 1 0];
            app.numofloopsforarm_2EditFieldLabel.Position = [28 252 129 22];
            app.numofloopsforarm_2EditFieldLabel.Text = 'num of loops for arm_2';

            % Create numofloopsforarm_2EditField
            app.numofloopsforarm_2EditField = uieditfield(app.LeftPanel, 'numeric');
            app.numofloopsforarm_2EditField.BackgroundColor = [0.0706 0.6196 1];
            app.numofloopsforarm_2EditField.Position = [189 253 36 22];
            app.numofloopsforarm_2EditField.Value = 1;

            % Create CenterPanel
            app.CenterPanel = uipanel(app.GridLayout);
            app.CenterPanel.BackgroundColor = [0 0 0];
            app.CenterPanel.Layout.Row = 1;
            app.CenterPanel.Layout.Column = 2;

            % Create UIAxes
            app.UIAxes = uiaxes(app.CenterPanel);
            title(app.UIAxes, 'Robot Motion')
            xlabel(app.UIAxes, 'X-axis(m)')
            ylabel(app.UIAxes, 'Y-axis(m)')
            app.UIAxes.PlotBoxAspectRatio = [1.0414201183432 1 1];
            app.UIAxes.Position = [6 6 398 472];

            % Create Switch
            app.Switch = uiswitch(app.CenterPanel, 'slider');
            app.Switch.Position = [359 445 19 8];
            app.Switch.Value = 'On';

            % Create RightPanel
            app.RightPanel = uipanel(app.GridLayout);
            app.RightPanel.BackgroundColor = [0.851 0.3255 0.098];
            app.RightPanel.Layout.Row = 1;
            app.RightPanel.Layout.Column = 3;

            % Create lengtharm_1mEditField_2Label
            app.lengtharm_1mEditField_2Label = uilabel(app.RightPanel);
            app.lengtharm_1mEditField_2Label.BackgroundColor = [0.851 0.3255 0.098];
            app.lengtharm_1mEditField_2Label.HorizontalAlignment = 'right';
            app.lengtharm_1mEditField_2Label.FontColor = [1 1 0];
            app.lengtharm_1mEditField_2Label.Position = [15 338 92 19];
            app.lengtharm_1mEditField_2Label.Text = 'length arm_1(m)';

            % Create lengtharm_1mEditField_2
            app.lengtharm_1mEditField_2 = uieditfield(app.RightPanel, 'numeric');
            app.lengtharm_1mEditField_2.BackgroundColor = [0.0745 0.6235 1];
            app.lengtharm_1mEditField_2.Position = [117 336 108 22];
            app.lengtharm_1mEditField_2.Value = 1;

            % Create lengtharm_2mEditField_2Label
            app.lengtharm_2mEditField_2Label = uilabel(app.RightPanel);
            app.lengtharm_2mEditField_2Label.HorizontalAlignment = 'right';
            app.lengtharm_2mEditField_2Label.FontColor = [1 1 0];
            app.lengtharm_2mEditField_2Label.Position = [15 294 97 22];
            app.lengtharm_2mEditField_2Label.Text = 'length arm_2 (m)';

            % Create lengtharm_2mEditField_2
            app.lengtharm_2mEditField_2 = uieditfield(app.RightPanel, 'numeric');
            app.lengtharm_2mEditField_2.RoundFractionalValues = 'on';
            app.lengtharm_2mEditField_2.BackgroundColor = [0.0745 0.6235 1];
            app.lengtharm_2mEditField_2.Position = [117 294 108 22];
            app.lengtharm_2mEditField_2.Value = 1;

            % Create anglearm_1DSlider_3Label
            app.anglearm_1DSlider_3Label = uilabel(app.RightPanel);
            app.anglearm_1DSlider_3Label.HorizontalAlignment = 'right';
            app.anglearm_1DSlider_3Label.FontColor = [1 1 0];
            app.anglearm_1DSlider_3Label.Position = [15 241 89 22];
            app.anglearm_1DSlider_3Label.Text = 'angle arm_1(D)';

            % Create anglearm_1DSlider_3
            app.anglearm_1DSlider_3 = uislider(app.RightPanel);
            app.anglearm_1DSlider_3.Limits = [0 180];
            app.anglearm_1DSlider_3.HandleVisibility = 'callback';
            app.anglearm_1DSlider_3.FontColor = [1 1 0];
            app.anglearm_1DSlider_3.Position = [125 250 81 3];

            % Create anglearm_2DSliderLabel
            app.anglearm_2DSliderLabel = uilabel(app.RightPanel);
            app.anglearm_2DSliderLabel.HorizontalAlignment = 'right';
            app.anglearm_2DSliderLabel.FontColor = [1 1 0];
            app.anglearm_2DSliderLabel.Position = [19 184 89 22];
            app.anglearm_2DSliderLabel.Text = 'angle arm_2(D)';

            % Create anglearm_2DSlider
            app.anglearm_2DSlider = uislider(app.RightPanel);
            app.anglearm_2DSlider.Limits = [0 360];
            app.anglearm_2DSlider.FontColor = [1 1 0];
            app.anglearm_2DSlider.Position = [129 193 81 3];

            % Create controlthelenghtofarmsLabel
            app.controlthelenghtofarmsLabel = uilabel(app.RightPanel);
            app.controlthelenghtofarmsLabel.FontName = 'Arial Black';
            app.controlthelenghtofarmsLabel.FontSize = 15;
            app.controlthelenghtofarmsLabel.FontColor = [1 1 0];
            app.controlthelenghtofarmsLabel.Position = [8 414 271 47];
            app.controlthelenghtofarmsLabel.Text = 'control the lenght of arms ';

            % Create andtheanglesLabel
            app.andtheanglesLabel = uilabel(app.RightPanel);
            app.andtheanglesLabel.FontName = 'Arial Black';
            app.andtheanglesLabel.FontSize = 15;
            app.andtheanglesLabel.FontColor = [1 1 0];
            app.andtheanglesLabel.Position = [50 392 126 23];
            app.andtheanglesLabel.Text = 'and the angles';

            % Create simulationButton_2
            app.simulationButton_2 = uibutton(app.RightPanel, 'push');
            app.simulationButton_2.ButtonPushedFcn = createCallbackFcn(app, @simulationButton_2Pushed, true);
            app.simulationButton_2.BackgroundColor = [0.9294 0.6902 0.1294];
            app.simulationButton_2.FontColor = [0.6353 0.0784 0.1843];
            app.simulationButton_2.Position = [70 111 100 22];
            app.simulationButton_2.Text = 'simulation';

            % Show the figure after all components are created
            app.UIFigure.Visible = 'on';
        end
    end

    % App creation and deletion
    methods (Access = public)

        % Construct app
        function app = Robot_Arm_design

            % Create UIFigure and components
            createComponents(app)

            % Register the app with App Designer
            registerApp(app, app.UIFigure)

            if nargout == 0
                clear app
            end
        end

        % Code that executes before app deletion
        function delete(app)

            % Delete UIFigure when app is deleted
            delete(app.UIFigure)
        end
    end
end