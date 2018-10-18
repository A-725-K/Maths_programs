function f_x = K_NearestNeighbor (S, newP, K)
  size_S = size(S, 1);  
  K
  index = 1;
  [min_dists, indexes] = sort(pdist2(newP, S(:, :)));
  
  estimator = sum(indexes(1:K))
  
  f_x = C = idivide(estimator, K, 'floor');
endfunction
