list = dir('./images');
N = length(list);
M = [];

for i = 3:N
    image = rgb2hsv(double(imread(['./images/', list(i).name])));
    
    [m, n, ~] = size(image);
    
    H = zeros(6, 1);
    S = zeros(2, 1);
    V = zeros(2, 1);
    %Histogram for Hue
    h = image(:, :, 1, :);
    idxH = max(1, ceil(h * 6));
    H = H + histc(idxH(:), 1:6);
    %Histogram for Saturation
    s = image(:, :, 2, :);
    idxS = max(1, ceil(s * 2));
    S = S + histc(idxS(:), 1:2);
    %Histogram for Value
    v = image(:, :, 3, :);
    idxV = max(1, ceil(v * 2));
    V = V + histc(idxV(:), 1:2);
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

save('RGB_Hist_HSV_10.txt', 'M', '-ASCII');
