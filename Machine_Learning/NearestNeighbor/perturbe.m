function X_EPS = perturbe(X, percentage)
  epsilon = zeros(size(X, 1), size(X, 2));
  epsilon(1:percentage*size(X,1), :) = rand(percentage*size(X, 1), size(X, 2));
  X_EPS = X + epsilon;
endfunction