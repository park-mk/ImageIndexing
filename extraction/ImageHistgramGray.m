list = dir('./images');
N = length(list);
M = [];

for i = 3:N
    image = double(imread(['./images/', list(i).name]));
    
    image = rgb2gray(image);
    
    [y, ~] = imhist(image);
    
    M = [M; y'];
end

save('Gray_Hist.txt', 'M', '-ASCII');
