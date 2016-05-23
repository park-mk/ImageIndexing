list = dir('./images');
N = length(list);
M = [];

for i = 3:N
    image = rgb2hsv(double(imread(['./images/', list(i).name])));
    
    H = image(:, :, 1);
    S = image(:, :, 2);
    V = image(:, :, 3);
    
    [yH, ~] = imhist(H);
    [yS, ~] = imhist(S);
    [yV, ~] = imhist(V);
    
    y = [yH' yS' yV'];
    
    M = [M; y];
end

save('HSV_Hist.txt', 'M', '-ASCII');
