/*
 * Copyright (C) 2019 Qiufeng54321
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
package com.qiufeng.erable.ast;

import static com.qiufeng.erable.Const.ID_LENGTH;
import com.qiufeng.erable.OpCode;
import com.qiufeng.erable.util.BitUtils;
import java.io.IOException;
import java.util.Arrays;

/**
 *
 * @author Qiufeng54321
 */
public class UnaryOpCode extends TempCode {

    public UnaryOpCode(int tid, OpCode op, Code parent) {
	super(tid, op, parent);
	if(op==OpCode.ADD){
	    this.op=OpCode.POS;
	}else if(op==OpCode.SUB){
	    this.op=OpCode.NEG;
	}
    }

    @Override
    public String toString() {
	return super.toString() + "  "+op + " @" + this.cid + " ->" + this.id;
    }
    /**
     * [OP 1B] [TARGET ID 4B] [ID 4B]<br>
     * [1] [1 2 3 4] [5 6 7 8]
     * Total: 9B
     * @throws IOException 
     */
    @Override
    public void write() throws IOException {
	System.out.println(this);
	this.writeOpCode(this.op);
	this.writeId(this.cid);
	this.writeId(this.id);
	System.out.println("__END "+this+"___");
    }
    
}