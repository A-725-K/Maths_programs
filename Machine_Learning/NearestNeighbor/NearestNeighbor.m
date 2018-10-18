% function index = NearestNeighbor(S, newP)
%
% S     (size: DxP)  = dataset
% newP  (size: 1xP)  = coordinates of the new point
% 
% index (size: 1x1)  = the index of the nearest point to newP in the dataset
%
% FORMULA: i' = arg min{||x_~ - x_i||^2 : 1 <= i <= n}
function index = NearestNeighbor(S, newP)
  size_S = size(S, 1);  
  
  index = 1;
  min_dist = pdist2(newP, S(1, :)); % optimization: min in theta(n-1)
  
  for i = 2 : size_S
    new_dist = pdist2(newP, S(i, :));
    if (new_dist < min_dist)
      min_dist = new_dist;
      index = i;
    endif
  endfor
endfunction