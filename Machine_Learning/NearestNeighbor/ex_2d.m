clear; clc;

%means = [[1;1], [3;1], [5;1], [7;1], [9;1], [11;1], [13;1], [19;1], [21;1], [23;1], [5;3], [7;3], [13;3], [19;3], [1;5], [3;5], [5;5], [7;5], [13;5], [19;5], [5;7], [7;7], [13;7], [19;7], [1;9], [3;9], [5;9], [7;9], [9;9], [11;9], [13;9], [19;9]];
means = [[0;0], [0;1], [1;1], [1;0]];
%sigmas = [0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2];
sigmas = [0.2, 0.2, 0.2, 0.2];

n = 100; %how much point per mean
dim = 25; %dimension of a point in the plot
max_x = 1; %max x coordinate 
max_y = 1; %max y coordinate
classes = 6 %how much equivalence classes

%generating the dataset
[coord, color] = MixGauss(means, sigmas, n);

% (--- optional ---) perturbation
%percentage = 0.79;
%x_eps = perturbe(coord, percentage); %use x_eps instead of Y in the future

% class of equivalence
Y = mod(color, classes);

%new point x~
new_x = max_x .* rand()
new_y = max_y .* rand()

%trying to guess his class
i = NearestNeighbor(coord, [new_x new_y])
nn_color = mod(color(i), classes)

%plotting the dataset and the new point
figure(1);
scatter(new_x, new_y, 800, nn_color, 'filled');
hold on;
scatter(coord(:,1), coord(:,2), dim, Y);
hold off;
title('my dataset')