function theta = linRegOneVar(theta, alpha, X, Y)
	while 1,
		diff = [0;0];
		for i = 1 : length(Y)
			c = theta' * X(:, i);
			c2 = c * X(2, i);
			diff = diff + [c; c2];
		end;
		
		if(diff(1) < 0.01)
			break;
		end;

		theta = theta - ((alpha / length(Y)) * diff);
	end;
end;
