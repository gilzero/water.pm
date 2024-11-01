import { Able } from "react-moveable/types";
export declare function getElementInfo(target: SVGElement | HTMLElement, container?: SVGElement | HTMLElement | null, rootContainer?: SVGElement | HTMLElement | null | undefined): import("react-moveable/types").MoveableElementInfo;
export declare function makeAble<Name extends string, AbleObject extends Partial<Able<any, any>>>(name: Name, able: AbleObject): {
    readonly events: AbleObject["events"] extends readonly any[] ? AbleObject["events"] : readonly [];
    readonly props: AbleObject["props"] extends readonly any[] ? AbleObject["props"] : readonly [];
    readonly name: Name;
} & AbleObject;
