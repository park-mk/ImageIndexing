list = dir('./images');
N = length(list);
M = [];

for i = 3:N
    image = imread(['./images/', list(i).name]);
    
    [m, n, ~] = size(image);
    
    R = zeros(12, 1);
    G = zeros(4, 1);
    B = zeros(4, 1);

    r = image(:, :, 1, :);
    idxR = max(1, ceil(r * 12));
    R = R + histc(idxR(:), 1:12);

    g = image(:, :, 2, :);
    idxG = max(1, ceil(g * 4));
    G = G + histc(idxG(:), 1:4);

    b = image(:, :, 3, :);
    idxB = max(1, ceil(b * 4));
    B = B + histc(idxB(:), 1:4);

    totalPixels = m * n;
    R = R / totalPixels;
    G = G / totalPixels;
    B = B / totalPixels;

    hsvHist = [R; G; B];
    
    y = hsvHist';
    
    M = [M; y];
end

save('RGB_Hist_10.txt', 'M', '-ASCII');
