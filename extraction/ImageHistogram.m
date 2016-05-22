list = dir('./images');
N = length(list);
M = [];

for i = 3:N
    image = imread(['./images/', list(i).name]);
    
    R = image(:, :, 1);
    G = image(:, :, 2);
    B = image(:, :, 3);
    
    [yR, ~] = imhist(R);
    [yG, ~] = imhist(G);
    [yB, ~] = imhist(B);
    
    y = [yR' yG' yB'];
    
    M = [M; y];
end

save('RGB_Hist.txt', 'M', '-ASCII');
