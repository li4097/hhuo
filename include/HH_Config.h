/*
Copyright (C) 2004  loveyou12300liumao@163.com

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/

#ifndef HH_CONFIG_H
#define HH_CONFIG_H

#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

namespace hhou
{
    /**
     * 读取配置文件类
     */
    typedef map<string, map<string, string> > gStorage;
    class HHConfig
    {
    private:
        fstream m_file; /// 文件操作对象
        const char *m_pName; /// 文件路径
        gStorage m_mKV; /// 配置保存的map
        int m_nError; /// 错误代码

    private:
		/**获取信息*/
        void GetInfo()
        {
            try
            {
                Parser();
            }
            catch (int i)
            {
                if (i == 1)
                    cerr << "[" << m_pName << "] A sections is missing" << endl;
                else
                    cerr << "[" << m_pName << "] Format error" << endl;
                m_nError = 1;
            }
        }

		/**解析*/
        void Parser()
        {
            string tmp;
            string section;
            while (getline(m_file, tmp))
            {
                if (!tmp.length())
					continue;
                if (tmp.at(0) == '[')
                    section = tmp.substr(1, tmp.length() - 2);
                else if (tmp.find("=") < tmp.length())
                {
                    if (section.length())
                        m_mKV[section][tmp.substr(0, tmp.find("="))] = tmp.substr(tmp.find("=") + 1);
                    else
                        throw 1;
                }
				else
				{
					cerr << tmp << "  ";
					throw 0;
				}
            }
        }

    public:
		/**
		 * 带参数的构造函数
		 * pName: ini文件的路径
		 */
		HHConfig(const char *pName) : m_pName(pName)
        {
            m_nError = 0;
            m_file.open(pName, ios::in);
            if (m_file.is_open())
            {
                GetInfo();
                m_file.close();
            }
        }

		/**
		 * 将内存中的kv更新到文件中
		 */
		~HHConfig()
        {
            map<string, string>	tmp;
            if (m_nError)
                return;
            m_file.open(m_pName, ios::out | ios::trunc);
            for (gStorage::iterator it = m_mKV.begin(); it != m_mKV.end(); ++it)
            {
                m_file << "[" << it->first << "]" << endl;
                tmp = it->second;
                for (map<string, string>::iterator it2 = tmp.begin(); it2 != tmp.end(); ++it2)
                    m_file << it2->first << "=" << it2->second << endl;
            }
            m_file.close();
        }

		/**
		 * 去掉string的空格
		 */
		void Trim(string &s)
		{
			size_t index = 0;
			if (!s.empty())
			{
				while ((index = s.find(' ', index)) != string::npos)
				{
					s.erase(index, 1);
				}
			}
		}

		/**
		 * 获取cfg文件中的值
		 * defalut：是不存在key的情况下的默认值
		 */
        string ReadStr(const string &section, const string &param, string defalut)
        {
			return m_mKV[section][param].empty() ? defalut : m_mKV[section][param];
        }

		/**
		 * 获取cfg文件中的值
		 * defalut：是不存在key的情况下的默认值
		 */
		int ReadInt(const string &section, const string &param, int defalut)
		{
			string strRet = m_mKV[section][param];
			if (strRet.empty())
				return defalut;
			Trim(strRet);
			return atoi(strRet.c_str());
		}

		/**
		 * 更新cfg文件中的值
		 */
        void Writeini(const string &section, const string &param, const string value)
        {
            m_mKV[section][param] = value;
        }

		/**
		 * 删除section的值
		 */
        void Remini(const string &param, const string &section = "")
        {
            if (m_nError)
                return;
            if (!param.length())
                m_mKV.erase(section);
            else
                m_mKV[section].erase(param);
        }

    public:
        /**单例模式*/
        static HHConfig &Instance(const char *pName = "../config/cfg.ini")
        {
            static HHConfig cfg(pName);
            return cfg;
        }
    };
}
#endif // HH_CONFIG_H
