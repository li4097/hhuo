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
#ifndef HH_CIRCULARBUFFER_H
#define HH_CIRCULARBUFFER_H

namespace hhou
{
	class HHCircularBuffer
	{
	public:
		HHCircularBuffer(size_t size);
		~HHCircularBuffer();

		/** append l bytes from p to buffer */
		bool Write(const char *p, size_t l);

		/** copy l bytes from buffer to dest */
		bool Read(char *dest, size_t l);

		/** skip l bytes from buffer */
		bool Remove(size_t l);

		/** total buffer length */
		size_t GetLength()
		{ return m_q; }

		/** pointer to circular buffer beginning */
		char *GetStart()
		{ return buf + m_b; }

		/** return number of bytes from circular buffer beginning to buffer physical end */
		size_t GetL()
		{ return (m_b + m_q > m_max) ? m_max - m_b : m_q; }

		/** return free space in buffer, number of bytes until buffer overrun */
		size_t Space()
		{ return m_max - m_q; }

		/** return total number of bytes written to this buffer, ever */
		unsigned long ByteCounter()
		{ return m_count; }

	private:
		HHCircularBuffer(const HHCircularBuffer &s) {}

		HHCircularBuffer &operator=(const HHCircularBuffer &)
		{ return *this; }

		char *buf;
		size_t m_max;
		size_t m_q;
		size_t m_b;
		size_t m_t;
		unsigned long m_count;
	};
}
#endif // HH_CIRCULARBUFFER_H
