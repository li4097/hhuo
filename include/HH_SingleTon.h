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

#ifndef HH_SINGLETON_H
#define HH_SINGLETON_H

namespace hhou
{
    /**
     * 单例的模板模式
     */
    template <class T>
    class HHSingleTon
    {
    public:
        static T *Instance()
        {
            if (m_pInstance == nullptr)
            {
                m_pInstance = new T;
                atexit(Destory);
            }
            return m_pInstance;
        }

    private:
        /**
         * 禁止拷贝和复制
         */
        HHSingleTon(const HHSingleTon &) {}
        HHSingleTon &operator=(const HHSingleTon &) {}

        /**
         * 释放资源
         */
        static void Destory()
        {
            if (m_pInstance)
            {
                delete m_pInstance;
                m_pInstance = nullptr;
            }
        }

    private:
        static T *m_pInstance;
    };

    template<class T> T* HHSingleTon<T>::m_pInstance = nullptr;
}

#endif // HH_SINGLETON_H