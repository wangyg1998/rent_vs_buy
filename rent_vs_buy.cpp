#include <iostream>

//ref 历年公积金商业贷款利率: <https://gjj.beijing.gov.cn/web/zwfw5/gjjsydkll/index.html>  

int main()
{
	float fang_chan_zeng_zhi = 0.01;//房价上涨空间
	float hui_bao_lv = 0.02;//租金回报率
	float dai_kuan_li_lv = 0.0375;//房贷利率
	float li_cai_zeng_zhi = 0.035;//理财收益率
	float _benjin = 300.f;
	float _fangjia = 300.f;
	float _daikuan = 200.f;
	int nianxian = 30;//计算周期

	std::cout << "本金: " << _benjin << "; 房价: " << _fangjia << "; 计算周期: " << nianxian << "年" << std::endl << std::endl;

	//租房
	{
		std::cout << "租房_: " << std::endl;
		float benjin = _benjin;
		float fangjia = _fangjia;
		for (int i = 0; i < nianxian; ++i)
		{
			fangjia += fangjia * fang_chan_zeng_zhi;
			float zujin = fangjia * hui_bao_lv;
			benjin -= zujin;

			benjin += benjin * li_cai_zeng_zhi;
		}
		std::cout << "剩余净资产: " << benjin << std::endl << std::endl;
	}

	//全款买房
	if (_benjin >= _fangjia)
	{
		std::cout << "全款买房_: " << std::endl;
		float benjin = _benjin;
		float fangjia = _fangjia;
		benjin -= fangjia;
		for (int i = 0; i < nianxian; ++i)
		{
			fangjia += fangjia * fang_chan_zeng_zhi;
			benjin += benjin * li_cai_zeng_zhi;
		}
		std::cout << "剩余净资产: " << benjin + fangjia << std::endl << std::endl;
	}

	//贷款买房_等额本金
	if (_benjin >= (_fangjia - _daikuan))
	{
		std::cout << "贷款买房_等额本金_: " << std::endl;
		std::cout << "贷款总额: " << _daikuan << std::endl;
		float benjin = _benjin;
		float fangjia = _fangjia;
		float daikuan = _daikuan;
		benjin -= (fangjia - daikuan);
		float lixi_sum = 0.f;

		float nian_huan_kuan = daikuan / static_cast<float>(nianxian);
		for (int i = 0; i < nianxian; ++i)
		{
			fangjia += fangjia * fang_chan_zeng_zhi;
			float lixi = daikuan * dai_kuan_li_lv;
			lixi_sum += lixi;
			daikuan -= nian_huan_kuan;
			benjin -= (nian_huan_kuan + lixi);

			benjin += benjin * li_cai_zeng_zhi;
		}
		std::cout << "房贷利息总额: " << lixi_sum << std::endl;
		if (benjin < 0.f)
		{
			std::cout << "资产(房产): " << fangjia << std::endl;
			std::cout << "负债: " << benjin << std::endl;
		}
		std::cout << "剩余净资产: " << benjin + fangjia << std::endl << std::endl;
	}

	system("pause");
	return 0;
}