function J = costFunction(X, Y, thetaZero, thetaOne)
	for i = 1 : length(thetaZero),
		for j = 1 : length(thetaOne)
			h = (thetaZero(i) + thetaOne(i) * X);
			J(i, j) = ((0.5) / length(Y)) * (h' * h);
		end
	end
end