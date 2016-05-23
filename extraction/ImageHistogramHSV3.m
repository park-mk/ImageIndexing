list = dir('./images');
N = length(list);
M = [];

for i = 3:N
    image = rgb2hsv(double(imread(['./images/', list(i).name])));
    
    [m, n, ~] = size(image);
    
    H = zeros(12, 1);
    S = zeros(4, 1);
    V = zeros(4, 1);
    %Histogram for Hue
    h = image(:, :, 1, :);
    idxH = max(1, ceil(h * 12));
    H = H + histc(idxH(:), 1:12);
    %Histogram for Saturation
    s = image(:, :, 2, :);
    idxS = max(1, ceil(s * 4));
    S = S + histc(idxS(:), 1:4);
    %Histogram for Value
    v = image(:, :, 3, :);
    idxV = max(1, ceil(v * 4));
    V = V + histc(idxV(:), 1:4);
    %Normalise the histograms
    totalPixels = m * n;
    H = H / totalPixels;
    S = S / totalPixels;
    V = V / totalPixels;
    %Concatenate the histograms
    hsvHist = [H; S; V];
    
    y = hsvHist';
    
    M = [M; y];
end

save('HSV_Hist_20.txt', 'M', '-ASCII');
