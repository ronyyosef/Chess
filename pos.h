#pragma once


namespace chess
{
	class POS
	{
	public:
		int row, col;
		POS(const POS& pos) :row(pos.row), col(pos.col) {}
		POS(const int& other_row, const int other_col) :row(other_row), col(other_col) {}
		POS() :row(-1), col(-1) {}
		bool operator==(const POS& other)const { return (other.row == row) && (other.col == col); }
		bool operator!=(const POS& other)const { return !(operator==(other)); }

	};
}


